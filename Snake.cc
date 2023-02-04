#include "Snake.hh"
#include <iostream>
#include <unistd.h>
#include <conio.h>      //for using kbhit

using namespace std;

void
Snake::initMap()
{
    snakePosX = mapWidth / 2;
    snakePosY = mapHeight / 2;

    generatefood();
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
                map[y][x] = Snake::BORDER;
            }
            else
            {
                if((x == 0) || x == mapWidth-1)
                {
                    map[y][x] = Snake::BORDER;
                }
                else
                {
                    if((x == snakePosX) && (y == snakePosY))
                    {
                        map[snakePosY][snakePosX] = Snake::SNAKE_HEAD;
                    }
                    else if((x == foodPosx) && (y==foodPosy))
                    {
                        map[foodPosy][foodPosx] = Snake::FOOD;
                    }
                    else
                    {
                        map[y][x] = Snake::EMPTY;
                    }

                    //add tail to the map
                    for(auto element:tail)
                    {
                        map[element.posY][element.posX] = Snake::TAIL;
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
            case Snake::EMPTY:
                cout << " ";
                break;
            case Snake::SNAKE_HEAD:
                cout<<"O";
                break;
            case Snake::BORDER:
                cout << "#";
                break;
            case Snake::FOOD:
                cout<<"X";
                break;
            case Snake::TAIL:
                cout<<"%";
                break;
            default:
                break;
            }

        }
        cout <<endl;
    }

    cout<< endl << snakePosX << " "<< snakePosY <<endl;
    cout << "Score: "<< score <<endl;
    usleep(SPEED_US);           //make the programme waiting
}

void Snake::game(){
    initMap();
    while(true)
    {
        if (kbhit()) {
            calculateDirection(char(getch()));
        }

        //generatefood();
        check();
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
}

void
Snake::move()
{

    //update tail
    if(tail.size()>0)
    {
        if((snakePosX == tail[0].posX) && (snakePosY == tail[0].posY))
        {
            //element added just now (only head shall move)
        }
        else
        {
            moveTail();
        }
    }
    moveHead();
}

void
Snake::moveHead()
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
Snake::moveTail()
{
    tailDataType temp0 = tail[0];
    tailDataType temp1;
    for(int i = 0; i<tail.size(); i++)
    {
        if(i==0)
        {
            tail[i].posX = snakePosX;
            tail[i].posY = snakePosY;
        }
        else
        {
            temp1 = tail[i];
            tail[i] = temp0;
            temp0 = temp1;
        }
    }
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

void
Snake::check()
{
    if((snakePosX == foodPosx) &&(snakePosY == foodPosy))
    {
        increaseTail();
        generatefood();
    }
}

void
Snake::increaseTail()
{
    score++;
    tailDataType element;
    element.posX = snakePosX;
    element.posY = snakePosY;
    // add element at beginning
    tail.insert(tail.begin(), element);
}