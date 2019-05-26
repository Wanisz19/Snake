#ifndef BOARDSNAKE_H
#define BOARDSNAKE_H
#include <cstdlib>
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
enum direction {UP, DOWN, LEFT, RIGHT};
enum game {RUNNING, WIN, LOSE};


struct State
{
    bool HasFood;
    bool HasHead;
     bool HasBody;
    bool HasWall;

};

struct Position
{
bool existing;
int PositionX;
int PositionY;
int previousX;
int previousY;


};




class BoardSnake
{


    game isgame;
    Position pos;
    direction dis;
    std::vector <Position> Snake;
    State Board[100][100];
    int BoardWidth;
    int BoardHeight;
    bool isfood;
    int foodX;
    int foodY;
    int Points;


    public:

        BoardSnake(int BoardWidth, int BoardHeight);
        void resetMap();
        void PositionFood();
        void debug_display() const;
        int getboardwidth() const;
        int getboardheight()const;
        void moveSnake();
        void eat();
        void stear();
        void rozgrywka();
        int getfoodX() const;
        int getfoodY() const;
        int getScore()const;







};




#endif // BOARDSNAKE_H
