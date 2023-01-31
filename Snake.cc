#include "Snake.hh"
#include <iostream>
#include <unistd.h>
#include <cstdlib>      //for using the function sleep
#include <conio.h>      //for using kbhit

using namespace std;

void
Snake::initMap()
{
    snakePosX = mapWidth / 2;
    snakePosY = mapHeight / 2;

    //place the snake
    //map[snakePosY][snakePosX] = 1;

    // setup the map
    updateMap();
}

void
Snake::updateMap()
{
    
    // setup the map
    for(auto y = 0; y<mapHeight; y++)
    {
        for(auto x = 0; x<mapWidth; x++)
        {
            if((y == 0) || (y == mapHeight-1))
            {
                map[y][x] = 2;
            }
            else
            {
                if((x == 0) || x == mapWidth-1)
                {
                    map[y][x] = 2;
                }
                else
                {
                    if(((x != snakePosX) && (y != snakePosY)) && ((x != foodPosx) && (y != foodPosy)))
                    {
                        map[y][x] = 0;
                    }
                    else
                    {
                        map[snakePosY][snakePosX] = 1;
                    }

                    if((x != foodPosx) && (y != foodPosy))
                    {
                        map[y][x] = 0;
                    }
                    else
                    {
                        map[foodPosy][foodPosx] = 3;
                    }

                }
            }
        }
    }
}

void
Snake::display()
{

    system("cls");

    for(auto y = 0; y<mapHeight; y++)
    {
        for(auto x = 0; x<mapWidth; x++)
        {
            switch (map[y][x])
            {
            case 0:
                cout << " ";
                break;
            case 1:
                cout<<"O";
                break;
            case 2:
                cout << "#";
                break;
            case 3:
                cout<<"X";
                break;
            default:
                break;
            }

        }
        cout <<endl;
    }

    cout<< endl << snakePosX << " "<< snakePosY <<endl;
    sleep(0.3);         //make the programme waiting
}

void Snake::game(){
    initMap();
    while(true)
    {
        if (kbhit()) {
            calculateDirection(char(getch()));
        }

        generatefood();
        move();

        updateMap();
        display();
        
    }

}

void Snake::generatefood()
{
    int x = rand() % (MAP_WIDTH - 2) + 1;
    int y = rand() % (MAP_HEIGHT - 2) + 1;

    foodPosx = x;
    foodPosy = y;

    // add food to the map
    //map[foodPosy][foodPosx] = 3;

}

void
Snake::move()
{



    snakePosX += directionX * 1;
    snakePosY += directionY * 1;

    if(snakePosX == 0)
        snakePosX = MAP_WIDTH - 2;
    if(snakePosX == MAP_WIDTH - 1)
        snakePosX = 1;

    if(snakePosY == 0)
        snakePosY = MAP_HEIGHT - 2;
    if(snakePosY == MAP_HEIGHT - 1)
        snakePosY = 1;
}

void
Snake::calculateDirection(char c)
{

    cout <<"calculateDirection     " << c<<endl;
    switch (c) {
    case 'w':
        if (directionY != 1)
        {
            directionY = -1;
            directionX = 0;
        }
        break;
    case 'd':
        if (directionX != -1)
        {
            directionX = 1;
            directionY = 0;
        }
        break;
    case 's':
        if (directionY != -1)
        {
            directionY = 1;
            directionX = 0;
        }
        break;
    case 'a':
        if (directionX != 1)
        {
            directionX = -1;
            directionY = 0;
        }
        break;
    }
}