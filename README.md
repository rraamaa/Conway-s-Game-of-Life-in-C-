Conway's Game of Life in C++
This repository contains a C++ implementation of Conway's Game of Life, a zero-player game simulating cellular automaton evolution based on initial user-defined configurations. The program uses a simple grid to represent cells, with customizable live and dead states, and computes generations based on predefined rules.

Features
1. Interactive Initialization:
   a. Users define initial live cell positions manually.
   b. Input validation ensures only valid grid positions are accepted.

2. Grid Visualization:
   a. Displays the grid with O representing live cells and . for dead cells.

3. Next Generation Calculation:
    a. Automatically applies the rules of Conway's Game of Life
       * Any live cell with fewer than 2 or more than 3 neighbors dies.
       * Any live cell with 2 or 3 neighbors survives.
       * Any dead cell with exactly 3 neighbors becomes alive.

4. Iterative Evolution:
    a. Continuously evolves generations based on user input.
    b. Allows users to decide when to stop the simulation.

Technical Details:
1. Programming Language: C++
2. Grid Size: Default 15x15, but can be modified by changing the SIZE constant.
3. Rules Implementation: Utilizes neighbor counting and conditional logic to simulate cellular evolution.
4. Console-Based UI: Provides a clear, text-based visualization of the grid.
