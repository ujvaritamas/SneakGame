#ifndef SNAKE_HH
#define SNAKE_HH

#define MAP_WIDTH 40
#define MAP_HEIGHT 20
#define SPEED_US 500
#include <vector>

class Snake{
public:
    void game();

private:

    void initMap();
    void updateMap();
    void display();

    void generatefood();

    void move();
    void moveHead();
    void moveTail();

    void calculateDirection(char c);

    void check();

    void increaseTail();

    const int mapWidth = MAP_WIDTH;
    const int mapHeight = MAP_HEIGHT;

    const int size = mapWidth * mapHeight;

    int map[MAP_HEIGHT][MAP_WIDTH] = {{0, 0}};

    int snakePosX;
    int snakePosY;
    int foodPosx = -1;
    int foodPosy = -1;

    int directionX = 0;
    int directionY = 0;

    int score = 0;

    enum
    {
        EMPTY = 0,
        SNAKE_HEAD = 1,
        BORDER = 2,
        FOOD = 3,
        TAIL = 4
    };

    struct tailDataType { // This structure is named "myDataType"
        int posX;
        int posY;
    };

    std::vector<tailDataType> tail;

};
#endif