/**
 * Joseph Le
 * Puzzle.cpp
 * 10/31/24
 *
 * This file implements the Puzzle class, which models a grid-based puzzle where tiles
 * must match their adjacent neighbors based on predefined edge complement rules. The
 * Puzzle class includes functionality to configure the grid, add and remove tiles,
 * and validate tile placement according to the rules of the puzzle.
 */
#include "Puzzle.h"
#include "PuzzleGUI.h"
#include "SimpleTest.h"

using namespace std;

/**
 * This function checks whether the specified tile can match its neighboring tile
 * at a given grid location (loc) and direction (dir). The function compares the
 * edge of the tile in the specified direction with the corresponding edge of the
 * neighboring tile. A match occurs if:
 * - The neighboring location is out-of-bounds, which guarantees a match.
 * - The neighboring tile is blank, which also guarantees a match.
 * - The edges of the two tiles complement each other
 */
bool Puzzle::canMatchEdge(Tile tile, GridLocation loc, Direction dir) const {
    if (dir == NORTH)
    {
        GridLocation other(loc.row - 1, loc.col);
        return other.row == -1 || tileAt(other).isBlank() || isComplement(tile.getEdge(NORTH), tileAt(other).getEdge(SOUTH));
    }
    else if (dir == EAST)
    {
        GridLocation other(loc.row, loc.col + 1);
        return other.col == _grid.numCols() || tileAt(other).isBlank() || isComplement(tile.getEdge(EAST), tileAt(other).getEdge(WEST));
    }
    else if (dir == SOUTH)
    {
        GridLocation other(loc.row + 1, loc.col);
        return other.row == _grid.numRows() || tileAt(other).isBlank() || isComplement(tile.getEdge(SOUTH), tileAt(other).getEdge(NORTH));
    }
    else
    {
        GridLocation other(loc.row, loc.col - 1);
        return other.col == -1 || tileAt(other).isBlank() || isComplement(tile.getEdge(WEST), tileAt(other).getEdge(EAST));
    }
}

/* Feel free to investigate the functions below, but you should not modify them */

// configures the puzzle with data read from the puzzle configuration file
void Puzzle::configure(int numRows, int numCols, Map<string, string>& pairs) {
    _complementMap = pairs;
    _grid.resize(numRows, numCols);
    _grid.clear();
    _numFilled = 0;
}

bool Puzzle::isFull() const {
    return _numFilled == _grid.size();
}

bool Puzzle::isEmpty() const {
    return _numFilled == 0;
}

bool Puzzle::canAdd(Tile tile) const {
    return !isFull() && canMatchAllEdges(tile, locationForCount(_numFilled));
}

void Puzzle::add(Tile tile) {
    if (isFull()) error("Cannot add to full grid!");
    GridLocation where = locationForCount(_numFilled);
    _grid[where] = tile;
    _numFilled++;
}

Tile Puzzle::remove() {
    if (isEmpty()) error("Cannot remove from empty grid!");
    GridLocation where = locationForCount(_numFilled - 1);
    Tile removed = _grid[where];
    _grid[where] = Tile(); // replace with blank tile
    _numFilled--;
    return removed;
}

// this is a little translation function to turn a 1-dimensional
// count into a 2-dimensional grid location
GridLocation Puzzle::locationForCount(int count) const {
    GridLocation loc;
    loc.row = count / _grid.numCols();
    loc.col = count % _grid.numCols();
    return loc;
}

// This is how we determine if two edges match (e.g., a red bottle top and a red bottle bottom)
// The map is populated with matching edge pairs read from the puzzle configuration file
bool Puzzle::isComplement(string one, string two) const {
    return _complementMap[one] == two;
}

//  verify each of the four edges of the tile matches its adjacent neighbor
bool Puzzle::canMatchAllEdges(Tile tile, GridLocation loc) const {
    for (Direction dir = NORTH; dir <= WEST; dir++) {
        if (!canMatchEdge(tile, loc, dir)) {
            return false;
        }
    }
    return true;
}

// access the tile at the given grid location
Tile Puzzle::tileAt(GridLocation loc) const {
    return _grid[loc];
}

// basic 2d traversal of the grid. Assumes the tile can print itself, as well
void Puzzle::print() const {
    GridLocation cur;
    for (cur.row = 0; cur.row < _grid.numRows(); cur.row++) {
        for (cur.col = 0; cur.col < _grid.numCols(); cur.col++) {
            cout << tileAt(cur) << "  ";
        }
        cout << endl;
    }
}
