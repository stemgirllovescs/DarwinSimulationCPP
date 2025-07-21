# DarwinSimulationCPP

A C++17 implementation of the classic **Darwin** “organism strategy” assignment for UT Austin’s *CS 371P: Object‑Oriented Programming* course.  
The program simulates multiple species competing on a grid. Each species is governed by a simple instruction set (e.g., `hop`, `left`, `right`, `infect`, conditional checks). Over successive rounds, the organisms follow their instructions, interact with neighbours, and attempt to dominate the board.

---

## Project Goals
1. **Explore OOP design** — clean class hierarchies for `World`, `Creature`, and `Species`.
2. **Model finite‑state behaviour** — each species is a tiny program with its own instruction pointer.
3. **Practice incremental development** — features were added checkpoint‑by‑checkpoint (HackerRank style), with new runner inputs at each stage.
4. **Strengthen test‑driven mindset** — separate test cases validate parsing, movement, infection rules, and boundary conditions.

---

## Roles & Contributions
| Team Member | Focus |
|-------------|-------|
| **Katherine Liang** (`stemgirllovescs`) | Core simulation engine, class design, instruction parser, world rendering. |
| **Teammate** | Designed and implemented unit / integration tests to verify behaviour in edge cases and randomized worlds. |

We also leveraged **ChatGPT** for debugging: prompts like *“Please debug my C++ code; I’m getting a segmentation fault in the infect logic”* helped identify pointer errors and improve runtime efficiency.

---

## Build & Run
```bash
# Compile
make            # uses the provided Makefile

# Run with a sample world definition
./Darwin sample.world
```

### File Formats
* `.spc` — species program files  (one instruction per line)  
* `.world` — initial board setup (rows, cols, followed by creature positions)

---

## Directory Guide
```
DarwinSimulationCPP/
├── Darwin.cpp          # main driver
├── World.{h,cpp}       # grid representation
├── Species.{h,cpp}     # instruction storage & parsing
├── Creature.{h,cpp}    # state of each organism
├── Makefile
├── tests/              # teammate’s test cases (Google Test)
└── sample/             # example .spc and .world files
```

---

## Key Concepts Demonstrated
- Object‑oriented modelling (encapsulation, inheritance)
- Finite‑state machines
- File I/O & robust parsing
- Incremental/refactoring workflow
- Team collaboration + test‑driven development

---

## License
MIT License — see `LICENSE` for details.
