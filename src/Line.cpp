//
// Created by marcel on 23.03.23.
//
#include "../inc/Line.h"

void Line::Move(Vector2D vec) {
    this->LinePoint[0].Move(vec);
    this->LinePoint[1].Move(vec);
}

void Line::Rotate(Point point_rot, double angle) {\
    this->LinePoint[0].Rotate(point_rot,angle);
    this->LinePoint[1].Rotate(point_rot,angle);
}

double Line::Calculate_length() {
    return this->LinePoint[0].Calculate_distance(this->LinePoint[1]);
}

bool Line::Point_on_line(Point point_check) {

    double a,b;
    a = this->Calculate_slope();
    b = this->Calculate_bfactor(a);

    if(!(point_check[1] == (point_check[0]*a + b)))
        return false;

    //x1 > x2
    if(LinePoint[0][0] > LinePoint[1][0]){
        // x3 > x1 || x3 < x2 -> is not on line
        if(point_check[0]>LinePoint[0][0] || point_check[0] < LinePoint[1][0] )
          return false;
    } else{ //x1 <x2
        // x3 > x2 || x3 < x1 -> is not on line
        if(point_check[0]>LinePoint[1][0] || point_check[0] < LinePoint[0][0] )
            return false;
    }
    // y1 > y2
    if(LinePoint[0][1] > LinePoint[1][1]){
        // y3 > y1 || y3 < y2 -> is not on line
        if(point_check[1]>LinePoint[0][1] || point_check[1] < LinePoint[0][1] )
            return false;
    } else{ //y1 <y2
        // y3 > y1 || y3 < y2 -> is not on line
        if(point_check[1]>LinePoint[0][1] || point_check[1] < LinePoint[1][1] )
            return false;
    }
    return true;
}

bool Line::Check_parallel(const Line line_check) {
    double aMain, aCheck;
    aMain = this->Calculate_slope();
    aCheck = Calculate_slope(line_check);

    return (aMain == aCheck);
}

bool Line::Check_perpendicular(const Line line_check) {
    double aMain, aCheck;
    aMain = this->Calculate_slope();
    aCheck = Calculate_slope(line_check);

    return (aMain == (1/-aCheck));
}

//TODO Intersection of 2 lines
Point Line::Intersection_point(const Line line) {
    Point tmpPoint[2];
    tmpPoint[0] = line.Give_Point(0);
    tmpPoint[1] = line.Give_Point(1);


//    if()

    return tmpPoint[0];
}

double Line::Calculate_slope() {

    if((LinePoint[1][0]-LinePoint[0][0]) == 0)
        return 0;
    // a = (y2 - y1) / (x2 - x1)
    return (LinePoint[1][1]-LinePoint[0][1])/(LinePoint[1][0]-LinePoint[0][0]);
}
double Line::Calculate_slope(const Line line_check) {
    Point tmpPoint[2];
    tmpPoint[0] = line_check.Give_Point(0);
    tmpPoint[1] = line_check.Give_Point(1);

    if((tmpPoint[1][0]-tmpPoint[0][0]) == 0)
        return 0;

    // a = (y2 - y1) / (x2 - x1)
    return (tmpPoint[1][1]-tmpPoint[0][1])/(tmpPoint[1][0]-tmpPoint[0][0]);
}

double Line::Calculate_bfactor(double a) {
    // b = y1 / (a * x1)
    return (LinePoint[0][1] / (a *LinePoint[0][0]));
}