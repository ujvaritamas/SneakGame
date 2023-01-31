#ifndef SNAKE_HH
#define SNAKE_HH

#define MAP_WIDTH 40
#define MAP_HEIGHT 20


class Snake{
public:
    void game();

private:

    void initMap();
    void updateMap();
    void display();

    void generatefood();

    
    const int mapWidth = MAP_WIDTH;
    const int mapHeight = MAP_HEIGHT;

    const int size = mapWidth * mapHeight;

    int map[MAP_HEIGHT][MAP_WIDTH] = {{0, 0}};

    int snakePosX;
    int snakePosY;
    int foodPosx = -1;
    int foodPosy = -1;



};
#endif