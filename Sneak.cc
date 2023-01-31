#include "Sneak.hh"
#include <iostream>

using namespace std;

void
Sneak::initMap()
{
    sneakPosX = mapWidth / 2;
    sneakPosY = mapHeight / 2;

    //place the snake
    map[sneakPosY][sneakPosX] = 1;

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
                    if((x != sneakPosX) && (y != sneakPosY))
                    {
                        map[y][x] = 0;
                    }
                }
            }
        }
    }
}

void
Sneak::display()
{
    for(auto y = 0; y<mapHeight; y++)
    {
        for(auto x = 0; x<mapWidth; x++)
        {
            switch (map[y][x])
            {
            case 0:
                cout << " ";
                break;
            case 2:
                cout << "#";
                break;
            case 1:
                cout<<"O";
                break;
            default:
                break;
            }

        }
        cout <<endl;
    }
}