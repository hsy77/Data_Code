#include <iostream>
#include "Maze.h"
int main() {
    int matrix[8][8]={
            {0,0,1,0,0,0,1,0},
            {0,0,1,0,0,0,1,0},
            {0,0,0,0,1,1,0,0},
            {0,1,1,1,0,0,0,0},
            {0,0,0,1,0,0,0,0},
            {0,1,0,0,0,1,0,0},
            {0,1,1,1,0,1,1,0},
            {1,1,0,0,0,0,0,0}
    };
    Maze maze;
    int n=8;
    maze.initMaze(*matrix,n);
    maze.printMaze();
    maze.PrintBfsPath();
    return 0;
}