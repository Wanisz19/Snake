#include "BoardSnake.h"
#include <unistd.h>
#include <cstdlib>

using namespace std;

 BoardSnake::BoardSnake(int BoardWidth, int BoardHeight)
{

    this->BoardWidth=BoardWidth;
    this->BoardHeight=BoardHeight;

    Snake.push_back( Position() );
    this->Snake[0].PositionX=10;
    this->Snake[0].PositionY=10;
    this->Snake[0].existing=true;
    isfood=false;
    isgame=RUNNING;
    Points=0;

resetMap();

}


void BoardSnake::resetMap()
{




  for(int idy=0;idy<BoardHeight;idy++)
    {
        for(int idx=0;idx<BoardWidth;idx++)
        {
            if(idy==0 || idy==BoardHeight-1 || idx==0 || idx==BoardWidth-1)
            {
                Board[idx][idy].HasWall=1;
            }

            else
            //{

           // Board[idx][idy].HasFood = 0;
            Board[idx][idy].HasHead = 0; // dlaczego bez  tych 2 deklaracji, waz bedzie sie ciagnał po całej mapie
            Board[idx][idy].HasBody = 0; //

            if(Board[idx][idy].HasWall==1 && Board[idx][idy].HasHead==1) ///kolizja...
            { isgame=LOSE; cout<<"PRZEGRANA";}
            //}
        }
    }

for( unsigned i=0; i<Snake.size(); i++ )
{
     if(Snake[i].existing==true && i==0)
            {
            Board[Snake[i].PositionX][Snake[i].PositionY].HasHead=1;
            }
        else if (Snake[i].existing==true && i>0)
            {
            Board[Snake[i].PositionX][Snake[i].PositionY].HasBody=1;
            }
}

}


void BoardSnake::PositionFood()
{

int licznik=0;
int x, y;

for(int idy=0;idy<BoardHeight;idy++)
    {
        for(int idx=0;idx<BoardWidth;idx++)
        {

        if(Board[idx][idy].HasFood==0)
        {
        licznik+=1;


            if(licznik==BoardHeight*BoardWidth)
             {

                    while(isfood !=true )
                    {
                     x=rand()%(BoardWidth-2)+1;
                    y=rand()%(BoardHeight-2)+1;

                    if(Board[x][y].HasBody==0 && Board[x][y].HasWall==0)
                    {
                    this->Board[x][y].HasFood=1;
                    isfood=true;
                    }

                    }
                    this->foodX=x;
                    this->foodY=y;

            }

            }


        }
    }


}


void BoardSnake::debug_display() const
{

    for(int idy=0;idy<BoardHeight;idy++)
    {
        for(int idx=0;idx<BoardWidth;idx++)
        {
            //Czy na polu znajduje siê mina

            cout<<'[';
            if(Board[idx][idy].HasBody==0 && Board[idx][idy].HasFood==1 && Board[idx][idy].HasWall==0 && Board[idx][idy].HasHead==0 )
            {
                cout<<"F";
            }
             if(Board[idx][idy].HasBody==0 && Board[idx][idy].HasFood==0 && Board[idx][idy].HasWall==0 && Board[idx][idy].HasHead==0)
            {
                cout<<" ";
            }


             if(Board[idx][idy].HasBody==1 && Board[idx][idy].HasFood==0 && Board[idx][idy].HasWall==0)
            {
                cout<<"B";
            }


             if(Board[idx][idy].HasBody==0 && Board[idx][idy].HasFood==0 && Board[idx][idy].HasWall==1 )
            {
                cout<<"#";
            }

              if(Board[idx][idy].HasBody==0 && Board[idx][idy].HasFood==0 && Board[idx][idy].HasWall==0 && Board[idx][idy].HasHead==1 )
            {
                cout<<"H";
            }


            cout<<']';
        }
        cout<<endl;
    }
}

int BoardSnake::getboardwidth() const
{return BoardWidth;}


int BoardSnake::getboardheight() const
{ return BoardHeight;}




void BoardSnake::eat()
{
    PositionFood();

    if( Snake[0].PositionX==foodX  && Snake[0].PositionY==foodY  )
    {
    Points+=10;
    Board[foodX][foodY].HasFood=0;
    Snake.push_back(Position());

    Snake[Snake.size()-1].PositionX = Snake[Snake.size()-2].PositionX;
    Snake[Snake.size()-1].PositionY= Snake[Snake.size()-2].PositionY;
    Snake[Snake.size()-1].existing=true;
    isfood=false; // powodouje generowanie jedzenia
    }


}







void BoardSnake::moveSnake() //(direction way)
{

    pos.previousX=Snake[0].PositionX;
    pos.previousY=Snake[0].PositionY;
    int newx;
    int newy;



    for( unsigned i=0; i<Snake.size(); i++ )
    {

        if(i == 0)
        {


            if (dis==UP)
                Snake[0].PositionY--;


            else if(dis==DOWN)
                Snake[0].PositionY++;

            else if(dis==LEFT)
                Snake[0].PositionX--;


           else if(dis==RIGHT)
                Snake[0].PositionX++;
        }


        else
        {
            newx = pos.previousX;
            newy = pos.previousY;
            pos.previousX=Snake[i].PositionX;
            pos.previousY=Snake[i].PositionY;
            Snake[i].PositionX = newx;
            Snake[i].PositionY = newy;
        }

    }
}

void BoardSnake::stear()
{
int kierunek;
cin>>kierunek;

        if(kierunek==1)
        {
        dis=UP;
        }

        if(kierunek==2)
        {
        dis=RIGHT;
        }
        if(kierunek==3)
        {
        dis=DOWN;
        }
        if(kierunek==4)
        {
        dis=LEFT;
        }



}
int BoardSnake::getfoodX() const
{return foodX;}

int BoardSnake::getfoodY() const
{return foodY;}





void BoardSnake::rozgrywka()
{

for(;;)
{
//PositionFood();
cout<< getScore();
eat();
stear();
debug_display();

//int x=1000000;
//usleep(x); //microsecunds

moveSnake();
resetMap();



//std::system("clear");


}

}
int BoardSnake::getScore() const
{
return Points;
}










