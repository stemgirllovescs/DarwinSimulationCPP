#include <algorithm> // count
#include <cstddef>   // ptrdiff_t
#include <string>    // string

#include "gtest/gtest.h"

#include "Darwin.hpp"

using namespace std;

class Instruction;
class Creature;
class Species;
class Darwin;


TEST (DarwinRun, test0)
{
    Species food, hopper, rover, trap;

    bool truth1 = true;
    bool truth2 = true;

    Darwin darwin(1, 2);

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

    
    darwin.add_species("f", food);
    darwin.add_species("h", hopper);
    darwin.add_species("r", rover);
    darwin.add_species("t", trap);

    string species_name(1, 't');
    darwin.add_creature(species_name, 0, 1, 'w');    

    darwin.simulate(2, 1);

    ASSERT_EQ(truth1, truth2);
}

TEST (DarwinRun, test1)
{
    Species food, hopper, rover, trap;

    bool truth1 = true;
    bool truth2 = true;

    Darwin darwin(114, 72);

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

    darwin.add_species("f", food);
    darwin.add_species("h", hopper);
    darwin.add_species("r", rover);
    darwin.add_species("t", trap);

    string species_name(1, 'h');
    darwin.add_creature(species_name, 104, 50, 'n');
    string species_name1(1, 't');
    darwin.add_creature(species_name1, 112, 39, 's');
    string species_name2(1, 'h');
    darwin.add_creature(species_name2, 94, 52, 'e');
    string species_name3(1, 't');
    darwin.add_creature(species_name3, 66, 1, 'w');
    string species_name4(1, 't');
    darwin.add_creature(species_name4, 51, 48, 's');
    string species_name5(1, 'f');
    darwin.add_creature(species_name5, 95, 64, 'w'); 
    string species_name6(1, 'r');
    darwin.add_creature(species_name6, 90, 1, 'n'); 
    string species_name7(1, 'h');
    darwin.add_creature(species_name7, 102, 27, 'n');
    string species_name8(1, 'f');
    darwin.add_creature(species_name8, 55, 54, 'w');
    string species_name9(1, 'r');
    darwin.add_creature(species_name9, 86, 51, 'w');    
    string species_name10(1, 'r');
    darwin.add_creature(species_name10, 41, 53, 's');
    string species_name11(1, 't');
    darwin.add_creature(species_name11, 92, 4, 'w');
    string species_name12(1, 'r');
    darwin.add_creature(species_name12, 5, 24, 'n');
    string species_name13(1, 'h');
    darwin.add_creature(species_name13, 86, 4, 's');
    string species_name14(1, 'r');
    darwin.add_creature(species_name14, 28, 4, 'w');
    string species_name15(1, 'f');
    darwin.add_creature(species_name15, 68, 60, 's');
    string species_name16(1, 'f');
    darwin.add_creature(species_name16, 49, 22, 'w');

    darwin.simulate(482, 68);

    ASSERT_EQ(truth1, truth2);
}

TEST(DarwinRun, test2)
{
    Species food, hopper, rover, trap;

    bool truth1 = true;
    bool truth2 = true;

    Darwin darwin(4, 7);

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

    darwin.add_species("f", food);
    darwin.add_species("h", hopper);
    darwin.add_species("r", rover);
    darwin.add_species("t", trap);

    string species_name(1, 't');
    darwin.add_creature(species_name, 3, 5, 's');
    string species_name1(1, 'f');
    darwin.add_creature(species_name1, 1, 4, 'n');
    string species_name2(1, 'h');
    darwin.add_creature(species_name2, 2, 1, 'w');
    string species_name3(1, 'f');
    darwin.add_creature(species_name3, 1, 4, 'e');
    string species_name4(1, 'h');
    darwin.add_creature(species_name4, 3, 0, 'e');

    darwin.simulate(1366, 1);

    ASSERT_EQ(truth1, truth2);
}

TEST (DarwinRun, test3)
{
    Species food, hopper, rover, trap;

    bool truth1 = true;
    bool truth2 = true;

    Darwin darwin(5, 6);

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

    darwin.add_species("f", food);
    darwin.add_species("h", hopper);
    darwin.add_species("r", rover);
    darwin.add_species("t", trap);
    
    string species_name(1, 'r');
    darwin.add_creature(species_name, 4, 2, 'w');
    string species_name1(1, 'h');
    darwin.add_creature(species_name1, 1, 0, 'n');
    string species_name2(1, 'f');
    darwin.add_creature(species_name2, 1, 4, 'e');

    darwin.simulate(1880, 185);

    ASSERT_EQ(truth1, truth2);
}

TEST (DarwinRun, test4)
{
    Species food, hopper, rover, trap;

    bool truth1 = true;
    bool truth2 = true;

    Darwin darwin(5, 6);

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

    darwin.add_species("f", food);
    darwin.add_species("h", hopper);
    darwin.add_species("r", rover);
    darwin.add_species("t", trap);
    
    string species_name(1, 't');
    darwin.add_creature(species_name, 4, 1, 'w');
    string species_name1(1, 't');
    darwin.add_creature(species_name1, 1, 3, 's');
    string species_name2(1, 'r');
    darwin.add_creature(species_name2, 4, 4, 's');

    darwin.simulate(1958, 51);

    ASSERT_EQ(truth1, truth2);
}

TEST (DarwinRun, test5)
{
    Species food, hopper, rover, trap;

    bool truth1 = true;
    bool truth2 = true;

    Darwin darwin(5, 6);

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

    darwin.add_species("f", food);
    darwin.add_species("h", hopper);
    darwin.add_species("r", rover);
    darwin.add_species("t", trap);
    
    string species_name(1, 'h');
    darwin.add_creature(species_name, 4, 2, 'e');
    string species_name1(1, 'h');
    darwin.add_creature(species_name1, 3, 4, 'n');
    string species_name2(1, 'f');
    darwin.add_creature(species_name2, 0, 0, 'n');

    darwin.simulate(47, 148);

    ASSERT_EQ(truth1, truth2);
}

TEST (DarwinRun, test6)
{
    Species food, hopper, rover, trap;

    bool truth1 = true;
    bool truth2 = true;

    Darwin darwin(5, 6);

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

    darwin.add_species("f", food);
    darwin.add_species("h", hopper);
    darwin.add_species("r", rover);
    darwin.add_species("t", trap);
    
    string species_name(1, 'h');
    darwin.add_creature(species_name, 0, 4, 'n');
    string species_name1(1, 'f');
    darwin.add_creature(species_name1, 4, 3, 's');
    string species_name2(1, 'h');
    darwin.add_creature(species_name2, 2, 4, 'n');

    darwin.simulate(919, 136);

    ASSERT_EQ(truth1, truth2);
}

TEST (DarwinRun, test7)
{
    Species food, hopper, rover, trap;

    bool truth1 = true;
    bool truth2 = true;

    Darwin darwin(5, 6);

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

    darwin.add_species("f", food);
    darwin.add_species("h", hopper);
    darwin.add_species("r", rover);
    darwin.add_species("t", trap);
    
    string species_name(1, 't');
    darwin.add_creature(species_name, 1, 1, 'n');
    string species_name1(1, 'h');
    darwin.add_creature(species_name1, 2, 5, 'w');
    string species_name2(1, 'r');
    darwin.add_creature(species_name2, 4, 4, 'w');

    darwin.simulate(416, 87);

    ASSERT_EQ(truth1, truth2);
}

TEST (DarwinRun, test8)
{
    Species food, hopper, rover, trap;

    bool truth1 = true;
    bool truth2 = true;

    Darwin darwin(5, 6);

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

    darwin.add_species("f", food);
    darwin.add_species("h", hopper);
    darwin.add_species("r", rover);
    darwin.add_species("t", trap);
    
    string species_name(1, 'h');
    darwin.add_creature(species_name, 0, 1, 'w');
    string species_name1(1, 'r');
    darwin.add_creature(species_name1, 4, 5, 's');
    string species_name2(1, 't');
    darwin.add_creature(species_name2, 1, 0, 'w');

    darwin.simulate(754, 172);

    ASSERT_EQ(truth1, truth2);
}

TEST (DarwinRun, test9)
{
    Species food, hopper, rover, trap;

    bool truth1 = true;
    bool truth2 = true;

    Darwin darwin(5, 6);

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

    darwin.add_species("f", food);
    darwin.add_species("h", hopper);
    darwin.add_species("r", rover);
    darwin.add_species("t", trap);
    
    string species_name(1, 'r');
    darwin.add_creature(species_name, 4, 4, 's');
    string species_name1(1, 't');
    darwin.add_creature(species_name1, 4, 2, 'w');
    string species_name2(1, 'f');
    darwin.add_creature(species_name2, 2, 5, 'n');

    darwin.simulate(921, 182);

    ASSERT_EQ(truth1, truth2);
}