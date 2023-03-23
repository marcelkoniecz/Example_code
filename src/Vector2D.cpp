//
// Created by marcel on 23.03.23.
//
#include "../inc/Vector2D.h"


Vector2D Vector2D::operator+(const Vector2D &vec) {
    return Vector2D((this->Coord[0]+vec[0]),(this->Coord[1]+vec[1]));
}

void Vector2D::operator+=(const Vector2D &vec) {
    this->Coord[0] = (this->Coord[0]+vec[0]);
    this->Coord[1] = (this->Coord[1]+vec[1]);
}


Vector2D Vector2D::operator-(const Vector2D &vec) {
    return Vector2D((this->Coord[0]-vec[0]),(this->Coord[1]-vec[1]));
}
