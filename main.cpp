#include <iostream>
#include "BoardSnake.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "BoardSnake.h"
#include "MSSFMLVIEW.h"
#include "SnakeController.h"
#include <unistd.h>

using namespace std;

int main()
{



srand(time(NULL));
BoardSnake p(13,13);
//p.PositionFood();
//p.debug_display();
//p.rozgrywka();

sf::RenderWindow window(sf::VideoMode(1000, 1000), "SNAKE");

MSSFMLVIEW m(5,5,50,p);
//SnakeController c(p,m);





    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();

            p.ButtonPressed(event);
           //m.ButtonPressed(event);

        }


        window.clear();

        m.draw(window);

        // Update the window
        window.display();
    }



    return 0;
}

