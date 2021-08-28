//
// Created by eslam on 28/08/2021.
//
#include "Hotel.h"
#ifndef UNTITLED1_HUMANHOTEL_H
#define UNTITLED1_HUMANHOTEL_H


class HumanHotel:public Hotel{
public:
    int room_num = 5;
    int night_cost = 500.0;
    int dry_cleaning_cost = 70.0;
    int spa_cost = 100.0;
    int total_cost;
};


#endif //UNTITLED1_HUMANHOTEL_H
