#include "console.h"
#include "vector.h"
#include "puzzle-solve.h"
#include <iostream>
using namespace std;


int main() {
    //Modify puzzle file here. Example puzzle files has been provided, feel free to add more!
    string puzzleFile = "puzzles/turtles/turtles.txt";

    tileMatch(puzzleFile);
    cout << "All done, exiting" << endl;
    return 0;
}
