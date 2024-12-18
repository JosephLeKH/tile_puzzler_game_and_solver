/*
 * Joseph Le
 * 10/31/24
 * puzzle-solve.cpp
 *
 * This file implements a puzzle-solving system for a tile-based puzzle game. The program
 * interacts with the user to load puzzle configurations, run an interactive puzzle-solving
 * session, and attempt to solve the puzzle using recursive backtracking. It uses the
 * Puzzle class to manage the grid and checks if tiles can be placed on the grid.
 */

#include "puzzle-solve.h"
#include "Puzzle.h"
#include "PuzzleGUI.h"
#include "SimpleTest.h"

using namespace std;

void tileMatch(string puzzleFile) {
    Puzzle puzzle;
    Vector<Tile> tiles;
    Action action;

    loadPuzzleConfig(puzzleFile, puzzle, tiles);
    updateDisplay(puzzle, tiles);

    do {
        action = playInteractive(puzzle, tiles);
        if (action == LOAD_NEW) {
            string configFile = chooseFileDialog();
            loadPuzzleConfig(configFile, puzzle, tiles);
            updateDisplay(puzzle, tiles);
        } else if (action == RUN_SOLVE) {
            bool success = solve(puzzle, tiles);
            cout << "Found solution to puzzle? " << boolalpha << success << endl;
            updateDisplay(puzzle, tiles);
        }
    } while (action != QUIT);
}

bool solve(Puzzle& puzzle, Vector<Tile>& tileVec) {
    if (tileVec.isEmpty())
    {
        return true;
    }

    for (int k = tileVec.size() - 1; k >= 0; k--)
    {
        Tile tile = tileVec.get(k);
        tileVec.remove(k);
        for (int i = 0; i < 4; i++)
        {
            tile.rotate();
            if(puzzle.canAdd(tile))
            {
                puzzle.add(tile);
                updateDisplay(puzzle, tileVec);

                solve(puzzle, tileVec);

                if(puzzle.isFull())
                {
                    return true;
                }

                puzzle.remove();
                updateDisplay(puzzle, tileVec);
            }
        }
        tileVec.add(tile);
    }

    return puzzle.isFull();
}
