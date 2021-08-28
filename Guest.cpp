//
// Created by eslam on 28/08/2021.
//
#include <iostream>
using namespace std;
#include "Guest.h"

void Guest:: ask_new_or_old(){
    cout << "Dear guest, are you a new or old guest? "<< endl;
    cin >> new_or_old;
}


void Guest:: create_account(){
    cout << "Dear guest, are you a monster or human? "<< endl;
    cin >> monster_or_human;

    cout << "Dear guest, What's your name? "<< endl;
    cin >> name;
    //id = generate_id();
}


int Guest:: ask_for_id(){
    cout << "Dear guest, What's your id? "<< endl;
    cin >> id;
    return id;
}


void Guest:: display_id(){
    cout << "Dear guest, Your id is: " << id << endl;
}