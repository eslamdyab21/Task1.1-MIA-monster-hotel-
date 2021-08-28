//
// Created by eslam on 28/08/2021.
//
#include <iostream>
using namespace std;
#include "Hotel.h"

int Hotel:: ask_num_rooms_and_nights() {
    cout << "Dear guest, what's the number of rooms you want to reserve? " << endl;
    cin >> reserved_rooms;

    cout << "Dear guest, what's the number of nights you plan to stay? " << endl;
    cin >> reserved_nights;

    return reserved_rooms, reserved_nights;
}

int Hotel:: ask_num_extra_nights(){
    cout << "Dear guest, what's the number of extra nights to reserve? "<< endl;
    cin >> extra_nights;

    return extra_nights;
}