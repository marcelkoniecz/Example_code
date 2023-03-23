//
// Created by marcel on 22.03.23.
//

#ifndef RACING_TEAM_POINT_H
#define RACING_TEAM_POINT_H

#include "Vector2D.h"

class Point{

    Vector2D Cord; //Coordinates 0 - x, 1 - y

public:
    Point():Cord(){}
    Point(double cordX,double cordY): Cord(cordX,cordY){}

    double operator[] (int a) const {return Cord[a];}
    double& operator[] (int a) {return Cord[a];}
    bool operator ==(Point point){ return (this->Cord[0] == point[0] && this->Cord[1] == point[1]);}

    void Move(Vector2D vec);
    void Rotate(Point point,double angle);
    double Calculate_distance(Point point);
    bool Comparison_with_offset(Point point_to_comp, double offset);
};
#endif //RACING_TEAM_POINT_H
