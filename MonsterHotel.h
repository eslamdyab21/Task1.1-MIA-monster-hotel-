//
// Created by eslam on 28/08/2021.
//
#include "Hotel.h"
#ifndef UNTITLED1_MONSTERHOTEL_H
#define UNTITLED1_MONSTERHOTEL_H


class MonsterHotel:public Hotel{
public:
    int room_num = 15;
    int night_cost = 200.0;
    int dry_cleaning_cost = 30.0;
    int spa_cost = 50.0;
    int total_cost;
};


#endif //UNTITLED1_MONSTERHOTEL_H
