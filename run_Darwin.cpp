#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include "Darwin.hpp"

using namespace std;

// Forward declarations
class Instruction;
class Creature;
class Species;
class Darwin;

int main() {
    // provides all the instructions for the specific darwin cases provided
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

        // creates the board and the species possible
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
            // makes the specific creatures obtained from the in txt
            string species_name(1, type);
            darwin.add_creature(species_name, row, col, dir);
        }

        int turns, freq;
        cin >> turns >> freq;

        // simulates the turns and prints at whatever frequency provided
        darwin.simulate(turns, freq);
    }

    return 0;
}