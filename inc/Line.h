//
// Created by marcel on 22.03.23.
//

#ifndef RACING_TEAM_LINE_H
#define RACING_TEAM_LINE_H

#include "Point.h"

class Line{
    Point LinePoint[2];
public:
    Line(Point point1, Point point2){
        LinePoint[0] = (point1);
        LinePoint[1] = (point2);
    }
    void Move(Vector2D vec);
    void Rotate(Point point_rot,double angle);
    double Calculate_length();
    bool Point_on_line(Point point_check);
    bool Check_parallel(const Line line_check);
    bool Check_perpendicular(const Line line_check);
    Point Intersection_point(const Line line);

    Point Give_Point(int a) const {return LinePoint[a];}

    double Calculate_slope();
    double Calculate_slope(const Line line_check);
    double Calculate_bfactor(double a);
    double Calculate_bfactor(const Line line_check, double a);
};
#endif //RACING_TEAM_LINE_H
