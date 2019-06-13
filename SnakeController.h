#ifndef SNAKECONTROLLER_H
#define SNAKECONTROLLER_H

#include <SFML/Graphics.hpp>
#include "MSSFMLVIEW.h"
#include "BoardSnake.h"
#include <time.h>

class SnakeController {
    //bool finished = false;   // do przełanczania ekranów

    //sf::Time times;
    //sf::Clock clocks;
    BoardSnake & snake;
    MSSFMLVIEW & view;
    // ... & model;
public:

    explicit SnakeController(BoardSnake & p, MSSFMLVIEW & m);
public:
    //void gameIsRunning();
    void handleEvent(sf::Event &event);

    // no need to change this
    void draw (sf::RenderWindow & win) { view.draw(win); }

  //  bool isFinished() const { return finished;}
};



#endif // MINESWEEPERCONTROLLER_H
