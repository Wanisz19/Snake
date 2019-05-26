#include <iostream>
#include "BoardSnake.h"
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(NULL));
BoardSnake p(20,20);
//p.PositionFood();
//cout<<p.getfoodX()<<endl;
//cout<<p.getfoodY();
p.rozgrywka();
//p.PositionFood();
p.debug_display();


    return 0;
}
