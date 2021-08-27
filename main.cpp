#include <iostream>
using namespace std;
#include <fstream>


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

    int ask_num_rooms_and_nights(){
        cout << "Dear guest, what's the number of rooms you want to reserve? "<< endl;
        cin >> reserved_rooms;

        cout << "Dear guest, what's the number of nights you plan to stay? "<< endl;
        cin >> reserved_nights;

        return reserved_rooms,reserved_nights;
    }

    int ask_num_extra_nights(){
        cout << "Dear guest, what's the number of extra nights to reserve? "<< endl;
        cin >> extra_nights;

        return extra_nights;
    }

};

class HumanHotel:public Hotel{
public:
    int room_num = 5;
    int night_cost = 500.0;
    int dry_cleaning_cost = 70.0;
    int spa_cost = 100.0;
    int total_cost;

};


class MonsterHotel:public Hotel{
public:
    int room_num = 15;
    int night_cost = 200.0;
    int dry_cleaning_cost = 30.0;
    int spa_cost = 50.0;
    int total_cost;

};

class Guest{
public:
    string monster_or_human;
    string name;
    string new_or_old;
    int id;

    void ask_new_or_old(){
        cout << "Dear guest, are you a new or old guest? "<< endl;
        cin >> new_or_old;
    }


    void create_account(){
        cout << "Dear guest, are you a monster or human? "<< endl;
        cin >> monster_or_human;

        cout << "Dear guest, What's your name? "<< endl;
        cin >> name;
        //id = generate_id();
    }


    int ask_for_id(){
        cout << "Dear guest, What's your id? "<< endl;
        cin >> id;
        return id;
    }


    void display_id(){
        cout << "Dear guest, Your id is: " << id << endl;
    }
};


//function that creates a file to store data
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


// function that take care of reservation
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

// function that take care of reservation
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


int main() {
    int guest_num = 5;
    int avalible_hum_rooms=5;
    int avalible_mon_rooms=15;

    Guest guests_arr [guest_num];

    // looping through guests and take inputs
    for(int i=0; i < guest_num; i++){
        guests_arr[i].ask_new_or_old();

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
        else if (guests_arr[i].new_or_old == "old")
        {
            int old_id = guests_arr[i].ask_for_id();
            old_id = old_id - 1;

            if(guests_arr[old_id].monster_or_human =="human") {
                hum_reservation(guests_arr[old_id].id,guests_arr[old_id].name,guest_num,i,&avalible_hum_rooms,guests_arr[i].monster_or_human);
            }
            else if (guests_arr[old_id].monster_or_human =="monster"){
                hum_reservation(guests_arr[old_id].id,guests_arr[old_id].name,guest_num,i,&avalible_mon_rooms,guests_arr[i].monster_or_human);
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
