#include "SnakeController.h"

SnakeController::SnakeController(BoardSnake & p, MSSFMLVIEW & m) :snake(p), view(m)
{}

void SnakeController::handleEvent(sf::Event &event)

{

if (event.type == sf::Event::KeyPressed)
{
    if (event.key.code == sf::Keyboard::Space)
    {
        std::cout << "the escape key was pressed" << std::endl;
        std::cout << "control:" << event.key.control << std::endl;
        std::cout << "alt:" << event.key.alt << std::endl;
        std::cout << "shift:" << event.key.shift << std::endl;
        std::cout << "system:" << event.key.system << std::endl;
    }
}


}




/*void SnakeController::gameIsRunning()
{
 times = clocks.getElapsedTime();




    if (times.asSeconds() >= 0.175)
        {

        //if(snake.isgame==RUNNING)
        //{
            snake.eat();
            snake.stear();
            clocks.restart();
            snake.resetMap();




        //}

    }


}
*/
