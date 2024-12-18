# Tile Puzzle Solver

## Overview

The **Tile Puzzle Solver** is a C++ program for solving grid-based tile puzzles. Each tile has edges (north, east, south, and west) with specific patterns that must match adjacent tiles in the grid. This project includes both manual and automated solving capabilities, complete with a graphical user interface (GUI) for visualization.

## Features

- **Interactive Mode**
  - Users can manually solve puzzles by selecting and placing tiles on the grid.
  - Support for rotating tiles to align patterns correctly.

- **Automated Solving**
  - The program uses recursive backtracking to automatically find solutions for puzzles.
  - Detects when no solution is possible and alerts the user.

- **Custom Puzzles**
  - Load puzzle configurations from text files for custom challenges.

- **Graphical User Interface**
  - Visualizes the puzzle grid, the stack of tiles, and solutions in real-time.

## Prerequisites

To build and run the Tile Puzzle Solver, ensure you have the following installed:

- **C++ Compiler**: Supports C++17 or higher (e.g., GCC, Clang, MSVC).
- **CMake**: Version 3.15 or higher.
- **SFML (Simple and Fast Multimedia Library)**: Version 2.5 or higher for GUI support.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/tile-puzzle-solver.git
   cd tile-puzzle-solver
   ```

2. Create a build directory and navigate to it:
   ```bash
   mkdir build && cd build
   ```

3. Configure the project using CMake:
   ```bash
   cmake ..
   ```

4. Build the project:
   ```bash
   make
   ```

5. Run the application:
   ```bash
   ./tile_puzzle_solver
   ```

## Usage

### Launching the Application

Run the program from the terminal or via an executable generated by the build process. The application opens in GUI mode by default.

### Interactive Mode

1. **Start Solving:** Begin solving the puzzle manually by dragging and dropping tiles onto the grid.
2. **Rotate Tiles:** Right-click on a tile to rotate it clockwise.
3. **Check Solution:** Click the "Check" button to verify if the solution is valid.

### Automated Solving Mode

1. Select "Auto Solve" from the menu to let the program solve the puzzle.
2. Observe the solving process as the program visualizes the steps taken.

### Custom Puzzle Input

- Prepare a text file describing the puzzle:
  - Format: Each line represents a tile with its edges described in order (north, east, south, west).
  - Example:
    ```
    A B C D
    E F G H
    I J K L
    ```
- Load the file from the GUI or pass it as a command-line argument:
  ```bash
  ./tile_puzzle_solver puzzle.txt
  ```

## File Structure

```
.
├── CMakeLists.txt      # Build configuration
├── src/                # Source files
├── include/            # Header files
├── assets/             # Tile images and other assets
├── puzzles/            # Example puzzle files
└── README.md           # Project documentation
```

## Acknowledgments

- SFML for providing the GUI framework.
- Puzzle-solving algorithms inspired by classic recursive backtracking techniques.
