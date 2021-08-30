#include <iostream>
using namespace std;
#include <fstream>
#include "Guest.h"
#include "HumanHotel.h"
#include "MonsterHotel.h"


void hum_reservation(int id, string name,int guest_num,int i,int *avalible_rooms,string monster_or_human);
void mon_reservation(int id, string name,int guest_num,int i,int *avalible_rooms,string monster_or_human);
void save_to_txt(int i,int id,string name,int reserved_rooms,int night_num,int total_cost,int room_num, int avalible_rooms,string monster_or_human);


int main() {
    int guest_num = 5;
    int avalible_hum_rooms=5;
    int avalible_mon_rooms=15;

    // create an object guest array with size of guests number
    Guest guests_arr [guest_num];

    // looping through guests and take inputs
    for(int i=0; i < guest_num; i++){
        guests_arr[i].ask_new_or_old();
        // TODO handling new guests (DONE)
        if (guests_arr[i].new_or_old == "new")
        {
            guests_arr[i].create_account();
            guests_arr[i].id = i+1;
            guests_arr[i].display_id();

            if(guests_arr[i].monster_or_human =="human") {
                HumanHotel hotel_arr [guest_num];
                hum_reservation(guests_arr[i].id,guests_arr[i].name,guest_num,i,&avalible_hum_rooms,guests_arr[i].monster_or_human);
            }
            else if (guests_arr[i].monster_or_human =="monster"){
                MonsterHotel hotel_arr [guest_num];
                mon_reservation(guests_arr[i].id,guests_arr[i].name,guest_num,i,&avalible_mon_rooms,guests_arr[i].monster_or_human);
            }

        }
        // TODO handling old guests (DONE)
        else if (guests_arr[i].new_or_old == "old")
        {
            int old_id = guests_arr[i].ask_for_id();
            old_id = old_id - 1;

            if(guests_arr[old_id].monster_or_human =="human") {
                hum_reservation(guests_arr[old_id].id,guests_arr[old_id].name,guest_num,i,&avalible_hum_rooms,guests_arr[i].monster_or_human);
            }

            else if (guests_arr[old_id].monster_or_human =="monster"){
                // realted to OLD Monsters problem, mon_reservation was hum_reservation
                // now it's running as excpected
                mon_reservation(guests_arr[old_id].id,guests_arr[old_id].name,guest_num,i,&avalible_mon_rooms,guests_arr[i].monster_or_human);
            }
        }

        if (avalible_hum_rooms ==0 & avalible_mon_rooms !=0){
            if(i+1 < guest_num){
                cout << "no more human rooms avalible" << endl;
            }
        }
        else if (avalible_hum_rooms !=0 & avalible_mon_rooms ==0){
            if(i+1 < guest_num){
                cout << "no more monster rooms avalible" << endl;
            }
        }
        else if (avalible_hum_rooms ==0 & avalible_mon_rooms ==0){
            cout << "Sorry no rooms avalible" << endl;
            break;
        }
    }

    return 0;
}


// TODO function that creates a text file to store data (DONE)
//  right now it has a problem with OLD Monsters (SOLVED)
//      it gets the occupied rooms (room_num - avalible_rooms)
//      and available rooms
//      and it doesn't desplay the name of the guest
void save_to_txt(int i,int id,string name,int reserved_rooms,int night_num,int total_cost,int room_num, int avalible_rooms,string monster_or_human){
    fstream myfile;
    if(i == 0){
        myfile.open("data.txt",ios::out);
        myfile << "class: "<< monster_or_human<< "\n";
        myfile << "id: "<< id<< "\n";
        myfile << "name: "<< name<< "\n";
        myfile <<"reserved_rooms: " << reserved_rooms<< "\n";
        myfile <<"nights number: " << night_num<< "\n";
        myfile <<"total cost: " << total_cost<< "\n";
        myfile <<"number of occupied rooms: " << room_num - avalible_rooms<< "\n";
        myfile <<"number of available rooms: " << avalible_rooms<< "\n";
        myfile <<"======================================="<< "\n";
        myfile.close();
    }
    else{
        myfile.open("data.txt",ios::app);
        myfile << "class: "<< monster_or_human<< "\n";
        myfile << "id: "<< id<< "\n";
        myfile << "name: "<< name<< "\n";
        myfile <<"reserved_rooms: " << reserved_rooms<< "\n";
        myfile <<"nights number: " << night_num<< "\n";
        myfile <<"total cost: " << total_cost<< "\n";
        myfile <<"number of occupied rooms: " << room_num - avalible_rooms<< "\n";
        myfile <<"number of available rooms: " << avalible_rooms<< "\n";
        myfile <<"======================================="<< "\n";
        myfile.close();
    }
}


// TODO function that take care of reservation for Humans (DONE)
//  keep track of Extend reservation
//  keep track of Additional services
//  keep track of Cancel reservation
void hum_reservation(int id, string name,int guest_num,int i,int *avalible_rooms,string monster_or_human){

    HumanHotel hotel;

    // New reservation
    hotel.reserved_rooms, hotel.night_num = hotel.ask_num_rooms_and_nights();
    *avalible_rooms = *avalible_rooms - hotel.reserved_rooms;
    if (*avalible_rooms >=0) {
        //Extend reservation
        hotel.extra_nights = hotel.ask_num_extra_nights();
        hotel.night_num = hotel.night_num + hotel.extra_nights;
        hotel.total_cost = (hotel.reserved_rooms) * (hotel.night_num) * (hotel.night_cost);

        //Additional services
        string ans;
        cout << "Do you want Dry cleaning? (yes or no)" << endl;
        cin >> ans;
        if(ans == "yes"){
            hotel.total_cost = hotel.total_cost + hotel.dry_cleaning_cost;
        }
        cout << "Do you want Spa? (yes or no)" << endl;
        cin >> ans;
        if(ans == "yes"){
            hotel.total_cost = hotel.total_cost + hotel.spa_cost;
        }

        cout << "Total cost is: " <<hotel.total_cost << endl;

        //Cancel reservation
        cout << "Do you want to cancel the reservation? (yes or no)" << endl;
        cin >> ans;
        if(ans == "yes"){
            hotel.total_cost = 0;
            *avalible_rooms = *avalible_rooms + hotel.reserved_rooms;
            hotel.reserved_rooms = 0;
            hotel.night_num = 0;
        }

        //create a file to store data
        save_to_txt(i,id,name,hotel.reserved_rooms,hotel.night_num,hotel.total_cost,hotel.room_num,*avalible_rooms,monster_or_human);
    }

    else{
        cout << "Sorry no human rooms avalible" << endl;
    }



}

// TODO function that take care of reservation for Monster (DONE)
//  keep track of Extend reservation
//  keep track of Additional services
//  keep track of Cancel reservation
void mon_reservation(int id, string name,int guest_num,int i,int *avalible_rooms,string monster_or_human){

    MonsterHotel hotel;

    // New reservation
    hotel.reserved_rooms, hotel.night_num = hotel.ask_num_rooms_and_nights();
    *avalible_rooms = *avalible_rooms - hotel.reserved_rooms;
    if (*avalible_rooms >=0) {
        //Extend reservation
        hotel.extra_nights = hotel.ask_num_extra_nights();
        hotel.night_num = hotel.night_num + hotel.extra_nights;
        hotel.total_cost = (hotel.reserved_rooms) * (hotel.night_num) * (hotel.night_cost);

        //Additional services
        string ans;
        cout << "Do you want Dry cleaning? (yes or no)" << endl;
        cin >> ans;
        if(ans == "yes"){
            hotel.total_cost = hotel.total_cost + hotel.dry_cleaning_cost;
        }
        cout << "Do you want Spa? (yes or no)" << endl;
        cin >> ans;
        if(ans == "yes"){
            hotel.total_cost = hotel.total_cost + hotel.spa_cost;
        }

        cout << "Total cost is: " <<hotel.total_cost << endl;

        //Cancel reservation
        cout << "Do you want to cancel the reservation? (yes or no)" << endl;
        cin >> ans;
        if(ans == "yes"){
            hotel.total_cost = 0;
            *avalible_rooms = *avalible_rooms + hotel.reserved_rooms;
            hotel.reserved_rooms = 0;
            hotel.night_num = 0;
        }

        //create a file to store data
        save_to_txt(i,id,name,hotel.reserved_rooms,hotel.night_num,hotel.total_cost,hotel.room_num,*avalible_rooms,monster_or_human);
    }

    else{
        cout << "Sorry no monster rooms avalible" << endl;
    }


}


