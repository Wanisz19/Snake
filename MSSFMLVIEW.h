#include <SFML/Graphics.hpp>
#include "BoardSnake.h"
#ifndef MSSFMLVIEW_H
#define MSSFMLVIEW_H


class MSSFMLVIEW
{

    sf::Event event;
    BoardSnake & snake;
    int x0, y0;
    int size_of_field;

public:
    MSSFMLVIEW(int x0, int y0, int size_of_field, BoardSnake &p);
    void draw(sf::RenderWindow &win);
    int getboardsize() const;
    int getx0() const;
    int gety0() const;
    void ButtonPressed (sf::Event &event);


};

#endif
