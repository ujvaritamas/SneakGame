#ifndef SNEAK_HH
#define SNEAK_HH

#define MAP_WIDTH 40
#define MAP_HEIGHT 20


class Sneak{
public:
    void initMap();
    //void updateMap();
    void display();

private:
    const int mapWidth = MAP_WIDTH;
    const int mapHeight = MAP_HEIGHT;

    const int size = mapWidth * mapHeight;

    int map[MAP_HEIGHT][MAP_WIDTH] = {{0, 0}};

    int sneakPosX;
    int sneakPosY;

    int foodPosx;
    int foodPosy;



};
#endif