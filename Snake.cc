#include "Snake.hh"
#include <iostream>
#include <unistd.h>
#include <cstdlib>      //for using the function sleep


using namespace std;

void
Snake::initMap()
{
    snakePosX = mapWidth / 2;
    snakePosY = mapHeight / 2;

    //place the snake
    map[snakePosY][snakePosX] = 1;

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
}

void Snake::game(){
    initMap();
    while(true)
    {
        generatefood();
        updateMap();
        display();
        sleep(5);         //make the programme waiting for 5 seconds
    }

}

void Snake::generatefood()
{
    int x = rand() % (MAP_WIDTH - 2) + 1;
    int y = rand() % (MAP_HEIGHT - 2) + 1;

    foodPosx = x;
    foodPosy = y;

    // add food to the map
    map[foodPosy][foodPosx] = 3;

}