//
// Created by marcel on 22.03.23.
//
#include "../inc/Point.h"
#include <iostream>
#include <cmath>

inline double Deg2Rad(double degree){
    return (degree*(M_PI/180));
}

void Point::Move(Vector2D vec){
    this->Cord += vec;
}

void Point::Rotate(Point roundPoint, double angle_degree) {
    //New tmpPoint helps to change coordinates in class
    Point tmpPoint(this->Cord[0] - roundPoint[0],this->Cord[1] - roundPoint[1]);

    double angle_rad = Deg2Rad(angle_degree);

    // xcos(angle) - ysin(angle) + round_point_coord_x
    // xsin(angle) + ycos(angle) + round_point_coord_y
    Cord[0] = tmpPoint[0]*cos(angle_rad) - tmpPoint[1]*sin(angle_rad) + roundPoint[0];
    Cord[1] = tmpPoint[0]*sin(angle_rad) + tmpPoint[1]*cos(angle_rad) + roundPoint[1];
}

double Point::Calculate_distance(Point givPoint) {
    double distance;

    // \sqrt{(x2-x1)^2 + (y2-y1)^2}
    distance = sqrt( pow((givPoint[0]-this->Cord[0]),2) + pow((givPoint[1] - this->Cord[1]),2));
    return distance;
}
// It is hard to check if rotations test without offset
bool Point::Comparison_with_offset(Point point_to_comp, double offset){
    return (this->Cord[0] - point_to_comp[0] <= offset && this->Cord[1] - point_to_comp[1] <= offset);
}