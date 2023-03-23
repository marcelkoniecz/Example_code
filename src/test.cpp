//
// Created by marcel on 23.03.23.
//

#include "../inc/test.h"
#include <iostream>
#include <math.h>


bool test(){
    if(!test_point())
        return false;
    //Todo Write line & triangle tests
//    if(!test_line())
//        return false;
//    if(!test_triangle())
//        return false;

    std::cout<<"All tests passed"<<std::endl;
    return true;
}


bool test_move_point() {
    // init_ - initial values, tmp - values to generate vector to move
    double initx, inity, tmp1, tmp2;
    srand (time(NULL));

    initx = rand()%100 -50;
    inity = rand()%100 -50;

    Point tmpPoint(initx, inity);
    for (int i= 0; i<10;i++) {
        tmp1 = rand()%100 -50;
        tmp2 = rand()%100 -50;
        initx += tmp1;
        inity += tmp2;
        tmpPoint.Move(Vector2D(tmp1, tmp2));
        if (!(tmpPoint == Point(initx, inity)))
            return false;
    }
    return true;
}

bool test_rotate_point(){

    double initx = 2, inity =3 ;
    Point tmpPoint(initx, inity);

    tmpPoint.Rotate(Point(0,0),-90);
    if(!(tmpPoint.Comparison_with_offset(Point(3,-2),0.1)))
        return false;

    tmpPoint.Rotate(Point(0,0),-90);
    if(!(tmpPoint.Comparison_with_offset(Point(-2,-3),0.1)))
        return false;

    tmpPoint.Rotate(Point(1,1),-90);
    if(!(tmpPoint.Comparison_with_offset(Point(-3,4),0.1)))
        return false;

    tmpPoint.Rotate(Point(4,-2),-90);
    if(!(tmpPoint.Comparison_with_offset(Point(10,5),0.1)))
        return false;

    return true;
}

bool test_calculate_distance(){

    double initx = 2, inity = 3;
    Point tmpPoint(initx, inity);
    if( 2 != tmpPoint.Calculate_distance(Point(initx + 2, inity)))
        return false;
    if( 5 != tmpPoint.Calculate_distance(Point(initx - 5 , inity)))
        return false;
    if( 1 != tmpPoint.Calculate_distance(Point(initx , inity + 1)))
        return false;
    if( 4 != tmpPoint.Calculate_distance(Point(initx , inity - 4)))
        return false;
    if( 5 != tmpPoint.Calculate_distance(Point(initx + 3, inity + 4 )))
        return false;

    return true;
}

bool test_point(){

    if(!test_move_point()){
        std::cout<< " Move point test failed"<<std::endl;
        return false;
    }
    if((!test_rotate_point())){
        std::cout<< " Rotate point test failed"<<std::endl;
        return false;
    }
    if(!(test_calculate_distance())){
        std::cout<< " Calculate distance to point test failed"<<std::endl;
        return false;
    }
    return true;
}


bool test_line(){
//    if(!test_calculate_length()){
//        std::cout<< " Move point test failed"<<std::endl;
//        return false;
//    }
//    if((!test_point_on_line())){
//        std::cout<< " Rotate point test failed"<<std::endl;
//        return false;
//    }
//    if(!(test_check_parallel())){
//        std::cout<< " Calculate distance to point test failed"<<std::endl;
//        return false;
//    }
//    if(!(test_check_perpendicular())){
//        return false;
//    }
    return true;
}