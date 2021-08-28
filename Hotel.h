//
// Created by eslam on 28/08/2021.
//

#ifndef UNTITLED1_HOTEL_H
#define UNTITLED1_HOTEL_H

class Hotel{
public:
    int room_num = 20;
    int reserved_rooms;
    int reserved_nights;
    int night_cost;
    int extra_nights;
    int night_num;
    int dry_cleaning_cost;
    int spa_cost;
    int total_cost;

    int ask_num_rooms_and_nights();

    int ask_num_extra_nights();

};

#endif //UNTITLED1_HOTEL_H
