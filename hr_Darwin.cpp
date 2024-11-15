#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

// Forward declarations
class Creature;
class Species;
class Darwin;

// Instruction class to represent each instruction in a species program
class Instruction {
public:
    enum Type { HOP, LEFT, RIGHT, INFECT, IF_EMPTY, IF_WALL, IF_RANDOM, IF_ENEMY, GO };

    Instruction(Type t, int n = 0) : type(t), param(n) {}

    Type type;
    int param;
};

// Species class to represent a type of creature and its program
class Species {
public:
    Species() = default;

    void add_instruction(Instruction::Type type, int param = 0) {
        program.push_back(Instruction(type, param));
    }

    const vector<Instruction>& get_program() const { return program; }

private:
    vector<Instruction> program;
};

class Creature {
public:
    Creature(const string& species_name, const Species* sp, char dir) 
        : species_type(species_name), species(sp), direction(dir), 
          program_counter(0), last_moved_turn(-1) {}

    bool execute_turn(Darwin& world, int row, int col, int current_turn);

    string get_species_type() const { return species_type; }
    char get_direction() const { return direction; }

    void set_species(const std::string& new_species_name, const Species* new_species) {
        species_type = new_species_name;
        species = new_species;
        program_counter = 0;
    }



private:
    string species_type;
    const Species* species;
    char direction;
    int program_counter;
    int last_moved_turn;

    void turn_left();
    void turn_right();
    bool can_move_forward(const Darwin& world, int row, int col) const;
    void get_forward_position(int row, int col, int& next_row, int& next_col) const;
    bool is_enemy_ahead(const Darwin& world, int row, int col) const;
};

class Darwin {
public:
    Darwin(int r, int c) : rows(r), cols(c), grid(r, vector<Creature*>(c, nullptr)) {
        srand(0);
    }

    void add_species(const string& name, const Species& species) {
        species_map[name] = species;
    }

    void add_creature(const string& species_name, int row, int col, char dir) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            delete grid[row][col];
            grid[row][col] = new Creature(species_name, &species_map[species_name], dir);
        }
    }

    void simulate(int turns, int freq) {
        cout << "*** Darwin " << rows << "x" << cols << " ***" << endl;
        print_grid(0);

        for (int turn = 1; turn <= turns; turn++) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j]) {
                        grid[i][j]->execute_turn(*this, i, j, turn);
                    }
                }
            }

            if (turn % freq == 0) {
                print_grid(turn);
            }
        }
    }

    bool is_valid_position(int row, int col) const {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    Creature* get_creature(int row, int col) const {
        if (is_valid_position(row, col)) {
            return grid[row][col];
        }
        return nullptr;
    }

    void move_creature(int from_row, int from_col, int to_row, int to_col) {
        if (is_valid_position(from_row, from_col) && is_valid_position(to_row, to_col)) {
            grid[to_row][to_col] = grid[from_row][from_col];
            grid[from_row][from_col] = nullptr;
        }
    }

    ~Darwin() {
        for (auto& row : grid) {
            for (auto creature : row) {
                delete creature;
            }
        }
    }

private:
    int rows, cols;
    vector<vector<Creature*>> grid;
    map<string, Species> species_map;

    void print_grid(int turn) const {
        cout << "Turn = " << turn << "." << endl;
        cout << "  ";
        for (int j = 0; j < cols; j++) {
            cout << j % 10;
        }
        cout << endl;

        for (int i = 0; i < rows; i++) {
            cout << i % 10 << " ";
            for (int j = 0; j < cols; j++) {
                cout << (grid[i][j] ? grid[i][j]->get_species_type()[0] : '.');
            }
            cout << endl;
        }
        cout << endl;
    }
};

void Creature::turn_left() {
    if (direction == 'n') direction = 'w';
    else if (direction == 'w') direction = 's';
    else if (direction == 's') direction = 'e';
    else if (direction == 'e') direction = 'n';
}

void Creature::turn_right() {
    if (direction == 'n') direction = 'e';
    else if (direction == 'e') direction = 's';
    else if (direction == 's') direction = 'w';
    else if (direction == 'w') direction = 'n';
}

void Creature::get_forward_position(int row, int col, int& next_row, int& next_col) const {
    next_row = row;
    next_col = col;

    if (direction == 'n') next_row--;
    else if (direction == 's') next_row++;
    else if (direction == 'e') next_col++;
    else if (direction == 'w') next_col--;
}

bool Creature::can_move_forward(const Darwin& world, int row, int col) const {
    int next_row, next_col;
    get_forward_position(row, col, next_row, next_col);
    return world.is_valid_position(next_row, next_col) && 
           world.get_creature(next_row, next_col) == nullptr;
}

bool Creature::is_enemy_ahead(const Darwin& world, int row, int col) const {
    int next_row, next_col;
    get_forward_position(row, col, next_row, next_col);

    if (!world.is_valid_position(next_row, next_col)) return false;

    Creature* ahead = world.get_creature(next_row, next_col);
    return ahead && ahead->get_species_type() != species_type;
}

bool Creature::execute_turn(Darwin& world, int row, int col, int current_turn) {
    if (last_moved_turn == current_turn) {
        return false;  // Already moved this turn
    }

    bool took_action = false;
    while (!took_action) {
        const Instruction& inst = species->get_program()[program_counter];
        
        switch (inst.type) {
            case Instruction::HOP: {
                if (can_move_forward(world, row, col)) {
                    int next_row, next_col;
                    get_forward_position(row, col, next_row, next_col);
                    world.move_creature(row, col, next_row, next_col);
                }
                took_action = true;
                break;
            }

            case Instruction::LEFT:
                turn_left();
                took_action = true;
                break;

            case Instruction::RIGHT:
                turn_right();
                took_action = true;
                break;

            case Instruction::INFECT: {
                int next_row, next_col;
                get_forward_position(row, col, next_row, next_col);
                if (is_enemy_ahead(world, row, col)) {
                    Creature* enemy = world.get_creature(next_row, next_col);
                    enemy->set_species(species_type, species);
                }
                took_action = true;
                break;
            }



            case Instruction::IF_EMPTY:
                if (can_move_forward(world, row, col)) {
                    program_counter = inst.param;
                    continue;
                }
                break;

            case Instruction::IF_WALL: {
                int next_row, next_col;
                get_forward_position(row, col, next_row, next_col);
                if (!world.is_valid_position(next_row, next_col)) {
                    program_counter = inst.param;
                    continue;
                }
                break;
            }

            case Instruction::IF_RANDOM:
                if (rand() % 2) {
                    program_counter = inst.param;
                    continue;
                }
                break;

            case Instruction::IF_ENEMY:
                if (is_enemy_ahead(world, row, col)) {
                    program_counter = inst.param;
                    continue;
                }
                break;

            case Instruction::GO:
                program_counter = inst.param;
                continue;
        }

        // Increment program counter and wrap around if necessary
        program_counter = (program_counter + 1) % species->get_program().size();
    }

    last_moved_turn = current_turn;
    return true;
}

int main() {
    Species food, hopper, rover, trap;

    food.add_instruction(Instruction::LEFT);
    food.add_instruction(Instruction::GO, 0);

    hopper.add_instruction(Instruction::HOP);
    hopper.add_instruction(Instruction::GO, 0);

    rover.add_instruction(Instruction::IF_ENEMY, 9);
    rover.add_instruction(Instruction::IF_EMPTY, 7);
    rover.add_instruction(Instruction::IF_RANDOM, 5);
    rover.add_instruction(Instruction::LEFT);
    rover.add_instruction(Instruction::GO, 0);
    rover.add_instruction(Instruction::RIGHT);
    rover.add_instruction(Instruction::GO, 0);
    rover.add_instruction(Instruction::HOP);
    rover.add_instruction(Instruction::GO, 0);
    rover.add_instruction(Instruction::INFECT);
    rover.add_instruction(Instruction::GO, 0);

    trap.add_instruction(Instruction::IF_ENEMY, 3);
    trap.add_instruction(Instruction::LEFT);
    trap.add_instruction(Instruction::GO, 0);
    trap.add_instruction(Instruction::INFECT);
    trap.add_instruction(Instruction::GO, 0);

    int t;
    cin >> t;
    cin.ignore(); // Skip the newline after t

    for (int test = 0; test < t; test++) {
        if (test > 0) cin.ignore();

        int rows, cols;
        cin >> rows >> cols;

        Darwin darwin(rows, cols);

        darwin.add_species("f", food);
        darwin.add_species("h", hopper);
        darwin.add_species("r", rover);
        darwin.add_species("t", trap);

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            char type;
            int row, col;
            char dir;
            cin >> type >> row >> col >> dir;

            string species_name(1, type);
            darwin.add_creature(species_name, row, col, dir);
        }

        int turns, freq;
        cin >> turns >> freq;

        darwin.simulate(turns, freq);
    }

    return 0;
}