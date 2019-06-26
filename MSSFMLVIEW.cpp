#include "MSSFMLVIEW.h"
#include <cstdlib>



MSSFMLVIEW::MSSFMLVIEW(int x0, int y0, int size_of_field, BoardSnake &p):snake(p)
{
    MSSFMLVIEW::x0=x0;
    MSSFMLVIEW::y0=y0;
    MSSFMLVIEW::size_of_field=size_of_field;
}

int MSSFMLVIEW::getboardsize() const
{
    return MSSFMLVIEW::size_of_field;
}
int MSSFMLVIEW::getx0() const
{
    return MSSFMLVIEW::x0;
}
int MSSFMLVIEW::gety0() const
{
    return MSSFMLVIEW::y0;
}





void MSSFMLVIEW::draw(sf::RenderWindow &win)
{
    snake.gameIsRunning();
    sf::Font font;
    sf::Text txt;
    if (font.loadFromFile("arial.ttf"))
    txt.setFont(font);
    txt.setFont(font);
    txt.setString("SAPER");
    txt.setPosition(700, 700);
    txt.setFillColor(sf::Color::Black);
    txt.setCharacterSize(100);
    win.draw(txt);
    for(int y=0; y<snake.getboardheight(); y++)
    {

        for(int x=0; x<snake.getboardwidth(); x++)
        {
            sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f)); // nie można wywołać fukcji getboardsize
            rectangle.setOutlineThickness(1.f);
            rectangle.setOutlineColor(sf::Color(23, 7, 249));

            int wierszy;
            int kolumnax;
            kolumnax=x*size_of_field+x0;
            wierszy=y*size_of_field+y0;

            if(snake.getFieldinfo(x,y)=='H')
            {
                rectangle.setFillColor(sf::Color(46, 107, 20));
                rectangle.setPosition(kolumnax,wierszy);
                win.draw(rectangle);
            }

            else if(snake.getFieldinfo(x,y)=='B')
            {
                rectangle.setFillColor(sf::Color(46, 107, 20));
                rectangle.setPosition(kolumnax,wierszy);
                win.draw(rectangle);
            }

            else if(snake.getFieldinfo(x,y)==' ')
            {
                rectangle.setFillColor(sf::Color(107, 115, 104));
                rectangle.setPosition(kolumnax,wierszy);
                win.draw(rectangle);
            }

            else if(snake.getFieldinfo(x,y)=='#')
            {
                rectangle.setFillColor(sf::Color(236,18,18));
                rectangle.setPosition(kolumnax,wierszy);
                win.draw(rectangle);
            }

            else if(snake.getFieldinfo(x,y)=='F')
            {
                rectangle.setFillColor(sf::Color(236, 18, 18));
                rectangle.setPosition(kolumnax,wierszy);
                win.draw(rectangle);
            }
        }
    }
}


void MSSFMLVIEW::ButtonPressed (sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::W)
        {
            std::cout << "the escape key was pressed" << std::endl;
            std::cout << "control:" << event.key.control << std::endl;
            std::cout << "alt:" << event.key.alt << std::endl;
            std::cout << "shift:" << event.key.shift << std::endl;
            std::cout << "system:" << event.key.system << std::endl;
        }
    }
}
















