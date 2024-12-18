/*
 *  This file contains the implementation of the Tile class
 */

#include "Tile.h"
#include "SimpleTest.h"

using namespace std;

Tile::Tile(string n, string e, string s, string w) {
    _id = n + e + s + w;    // sets an id for internal use, do not change this line!

    _north = n;
    _east = e;
    _south = s;
    _west = w;
}

string Tile::getEdge(Direction dir) const {
    if (dir == NORTH)
    {
        return _north;
    }
    else if (dir == EAST)
    {
        return _east;
    }
    else if (dir == SOUTH)
    {
        return _south;
    }
    return _west;
}

void Tile::rotate() {
    string n = _north;
    string e = _east;
    string s = _south;
    string w = _west;

    _north = w;
    _east = n;
    _south = e;
    _west = s;
}


Tile::Tile() : Tile("","","","") {}    // default constructor creates blank tile

bool Tile::isBlank() const {
    return (_north == "" && _east == "" && _south == "" && _west == "");
}

string Tile::displayTileStr() const{
    string s;
    s += "  " + _north + "\n";
    s += _west;
    s += "   " + _east + "\n";
    s += "  " + _south + "\n";
    return s;
}

string Tile::toString() const {
    return _north + "-" + _east + "-" + _south + "-" + _west;
}

