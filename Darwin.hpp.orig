#ifndef Darwin_hpp
#define Darwin_hpp

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
    // the different types of instructions to know what to do next by category
    enum Type { HOP, LEFT, RIGHT, INFECT, IF_EMPTY, IF_WALL, IF_RANDOM, IF_ENEMY, GO };

    // takes in an enum type and a parameter
    // doesn't make an extra copy
    Instruction(Type t, int n = 0) : type(t), param(n) {}

    Type type;
    int param;
};

// Species class to represent a type of creature and its program
class Species {
public:
    // dafault constructor
    Species() = default;

    void add_instruction(Instruction::Type type, int param = 0) {
        program.push_back(Instruction(type, param));
    }

    // returns the set of instructions
    const vector<Instruction>& get_program() const { return program; }

private:
    vector<Instruction> program;
};

// an individual creature of some sort of Species
class Creature {
public:

    // initializes with a species name, it's individual pointer to the species' instruction, and a cahracter for
    // the direction
    Creature(const string& species_name, const Species* sp, char dir) 
        : species_type(species_name), species(sp), direction(dir), 
          program_counter(0), last_moved_turn(-1) {}

    bool execute_turn(Darwin& world, int row, int col, int current_turn);

    // gets the information for the species type and direction
    string get_species_type() const { return species_type; }
    char get_direction() const { return direction; }

    // to change the species upon infection
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

// the main program for Darwin
class Darwin {
public:

    // to initialize the board "pseudo-randomly"
    Darwin(int r, int c) : rows(r), cols(c), grid(r, vector<Creature*>(c, nullptr)) {
        srand(0);
    }

    // add species to the Darwin that is able to pop up or not
    void add_species(const string& name, const Species& species) {
        species_map[name] = species;
    }

    // add a creature to the board, and given a default orientation
    void add_creature(const string& species_name, int row, int col, char dir) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            delete grid[row][col];
            grid[row][col] = new Creature(species_name, &species_map[species_name], dir);
        }
    }

    // runs the basis of the simulation for the board given how many turns
    // and how frequently it wants to be printed
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

    // checks if the propsed row and column exists on the board
    bool is_valid_position(int row, int col) const {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }

    // gets a local lil critter
    Creature* get_creature(int row, int col) const {
        if (is_valid_position(row, col)) {
            return grid[row][col];
        }
        return nullptr;
    }

    // moves the creature from one space to another if the position is valid
    void move_creature(int from_row, int from_col, int to_row, int to_col) {
        if (is_valid_position(from_row, from_col) && is_valid_position(to_row, to_col)) {
            grid[to_row][to_col] = grid[from_row][from_col];
            grid[from_row][from_col] = nullptr;
        }
    }

    // printing for testing purposes
    void print_offgrid(int turn) const {
        
        // vector<vector<string>> grid;
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

    // cleans up the board
    ~Darwin() {
        for (auto& row : grid) {
            for (auto creature : row) {
                delete creature;
            }
        }
    }

private:

    // prints the grid
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

// these changes the orientation of the creature and marks it accordingly
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

// gets the next position based on what direction it's facing
void Creature::get_forward_position(int row, int col, int& next_row, int& next_col) const {
    next_row = row;
    next_col = col;

    if (direction == 'n') next_row--;
    else if (direction == 's') next_row++;
    else if (direction == 'e') next_col++;
    else if (direction == 'w') next_col--;
}

// checks if the position it wants to move forward in is a valid place to move
bool Creature::can_move_forward(const Darwin& world, int row, int col) const {
    int next_row, next_col;
    get_forward_position(row, col, next_row, next_col);
    return world.is_valid_position(next_row, next_col) && 
           world.get_creature(next_row, next_col) == nullptr;
}

// checks if there's an 'enemy' in front of the creature based on what direction it's
// facing
bool Creature::is_enemy_ahead(const Darwin& world, int row, int col) const {
    int next_row, next_col;
    get_forward_position(row, col, next_row, next_col);

    if (!world.is_valid_position(next_row, next_col)) return false;

    Creature* ahead = world.get_creature(next_row, next_col);
    return ahead && ahead->get_species_type() != species_type;
}

// checks if a creature has had its turn
bool Creature::execute_turn(Darwin& world, int row, int col, int current_turn) {
    if (last_moved_turn == current_turn) {
        return false;  // Already moved this turn
    }

    bool took_action = false;
    while (!took_action) {

        // checks through the different instruction types (enums) and executes the appropriate one
        // for the creature using the program counter
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

#endif // Darwin_hpp