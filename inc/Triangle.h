//
// Created by marcel on 22.03.23.
//

#ifndef RACING_TEAM_TRIANGLE_H
#define RACING_TEAM_TRIANGLE_H

#include "Point.h"


class Triangle{
    Point TrianglePoint[3];
    bool isRectangular;
public:

    void Move(Vector2D vec);
    void Rotate(Point point_rot,double angle);
    double Calc_area();
    double Calc_perimeter();
    bool Check_joint(Triangle triangle_check);
    double Calc_hypotenuse();
};
#endif //RACING_TEAM_TRIANGLE_H
