#ifndef INTERFACEMANAGER_H
#define INTERFACEMANAGER_H

struct skelPart
{
    struct skelCoordinates HeadCoord;
    struct skelCoordinates BodyCoord;
    struct skelCoordinates MouseCoord;

    struct skelCoordinates rightShoulderCoord;
    struct skelCoordinates leftShoulderCoord;

    struct skelCoordinates rightArmCoord;
    struct skelCoordinates leftArmCoord;

    struct skelCoordinates rightHandCoord;
    struct skelCoordinates leftHandCoord;

    struct skelCoordinates rightThumbCoord;
    struct skelCoordinates leftThumbCoord;

};

struct skelCoordinates
{
    int x;
    int y;
};

class interfacemanager
{
public:
    interfacemanager();
};

#endif // INTERFACEMANAGER_H
