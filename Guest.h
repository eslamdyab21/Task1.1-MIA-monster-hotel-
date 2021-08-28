//
// Created by eslam on 28/08/2021.
//

#ifndef UNTITLED1_GUEST_H
#define UNTITLED1_GUEST_H


class Guest{
public:
    string monster_or_human;
    string name;
    string new_or_old;
    int id;

    void ask_new_or_old();


    void create_account();


    int ask_for_id();


    void display_id();
};


#endif //UNTITLED1_GUEST_H
