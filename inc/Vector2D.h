//
// Created by marcel on 22.03.23.
//

#ifndef RACING_TEAM_VECTOR2D_H
#define RACING_TEAM_VECTOR2D_H

#include <vector>

class Vector2D{

    std::vector<double> Coord;

public:
    Vector2D(){Coord.reserve(2); Coord[0] = 0; Coord[1] = 0;}
    Vector2D(const double x,const double y) {Coord.reserve(2); Coord[0] = x; Coord[1] = y;}
    double operator[] (int a) const {return Coord[a];}
    double& operator[] (int a) {return Coord[a];}
    void operator +=(const Vector2D &vec);
    Vector2D operator *(const Vector2D &vec);
    Vector2D operator +(const Vector2D &vec);
    Vector2D operator -(const Vector2D &vec);
};
#endif //RACING_TEAM_VECTOR2D_H
