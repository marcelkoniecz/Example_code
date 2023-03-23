//
// Created by marcel on 23.03.23.
//

#include "../inc/Triangle.h"
#include "../inc/Line.h"
void Triangle::Move(Vector2D vec) {
    this->TrianglePoint[0].Move(vec);
    this->TrianglePoint[1].Move(vec);
    this->TrianglePoint[2].Move(vec);
}

void Triangle::Rotate(Point point_rot, double angle) {
    this->TrianglePoint[0].Rotate(point_rot,angle);
    this->TrianglePoint[1].Rotate(point_rot,angle);
    this->TrianglePoint[1].Rotate(point_rot,angle);

}

//TODO - 2 functions
double Triangle::Calc_area() {}
bool Triangle::Check_joint(Triangle triangle_check) {}

double Triangle::Calc_perimeter() {
    double perimeter = 0;
    Line tmpLines[] = {Line(TrianglePoint[0],TrianglePoint[1]),
                       Line(TrianglePoint[1],TrianglePoint[2]),
                       Line(TrianglePoint[2],TrianglePoint[0])};

    for(auto& x:tmpLines){
       perimeter+= tmpLines->Calculate_length();
    }
    return perimeter;
}

double Triangle::Calc_hypotenuse() {
    if(!isRectangular)
        return 0;
    double perimeter = 0;
    Line tmpLines[] = {Line(TrianglePoint[0],TrianglePoint[1]),
                       Line(TrianglePoint[1],TrianglePoint[2]),
                       Line(TrianglePoint[2],TrianglePoint[0])};

    for(auto& x:tmpLines){
        if (perimeter < tmpLines->Calculate_length()){
            perimeter = tmpLines->Calculate_length();
        }
    }
    return perimeter;
}