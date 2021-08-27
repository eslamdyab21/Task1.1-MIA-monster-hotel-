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
    int id=0;

    void ask_new_or_old(){
        cout << "Dear guest, are you a new or old guest? "<< endl;
        cin >> new_or_old;
    }


    void create_account(){
        cout << "Dear guest, are you a monster or human? "<< endl;
        cin >> monster_or_human;

        cout << "Dear guest, What's your name? "<< endl;
        cin >> name;
        id = generate_id();
    }


    int generate_id(){
        return id + 1;
    }


    void ask_for_id(){
        cout << "Dear guest, What's your id? "<< endl;
        cin >> id;
    }


    void display_id(){
        cout << "Dear guest, Your id is: " << id << endl;
    }
};




// function that take care of reservation
int reservation(string monster_or_human, int id, string name,int guest_num,int i){
    int avalible_rooms;
    HumanHotel hotel;

    if(monster_or_human =="human") {
        HumanHotel hotel;
        avalible_rooms = 5;
    }
    else if (monster_or_human =="monster"){
        MonsterHotel hotel;
        avalible_rooms = 15;
    }

    // New reservation
    if (avalible_rooms >0) {
        hotel.reserved_rooms, hotel.night_num = hotel.ask_num_rooms_and_nights();
        avalible_rooms = avalible_rooms- hotel.reserved_rooms;

        hotel.total_cost = (hotel.reserved_rooms) * (hotel.night_num) * (hotel.night_cost);
        }

    else{
        cout << "Sorry no rooms avalible" << endl;
    }

    //Extend reservation
    hotel.extra_nights = hotel.ask_num_extra_nights();
    hotel.reserved_rooms = hotel.reserved_rooms + hotel.extra_nights;
    hotel.total_cost = hotel.total_cost + (hotel.extra_nights)*(hotel.night_cost);

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
    }

    //create a file to store data
    fstream myfile;
    if(i == 0){
        myfile.open("data.txt",ios::out);
        myfile << "id: "<< id<< "\n";
        myfile << "name: "<< name<< "\n";
        myfile <<"reserved_rooms: " << hotel.reserved_rooms<< "\n";
        myfile <<"nights number: " << hotel.night_num<< "\n";
        myfile <<"total cost: " << hotel.total_cost<< "\n";
        myfile <<"======================================="<< "\n";
        myfile.close();
    }
    else{
        myfile.open("data.txt",ios::app);
        myfile << id<< "," + name +"\n";
        myfile <<"reserved_rooms: " << hotel.reserved_rooms<< "\n";
        myfile <<"nights number: " << hotel.night_num<< "\n";
        myfile <<"total cost: " << hotel.total_cost<< "\n";
        myfile <<"======================================="<< "\n";
        myfile.close();
    }


    return avalible_rooms;

}



int main() {
    int guest_num = 2;
    int avalible_rooms=20;


    // looping through guests and take inputs
    for(int i=0; i < guest_num; i++){
        Guest guest;
        guest.ask_new_or_old();

        if (guest.new_or_old == "new")
        {
            guest.create_account();
            guest.display_id();
        }
        else if (guest.new_or_old == "old")
        {
            guest.ask_for_id();
        }

        avalible_rooms = reservation(guest.monster_or_human,guest.id,guest.name,guest_num,i);
        if (avalible_rooms ==0){
            cout << "Sorry no rooms avalible" << endl;
            break;
        }
    }

    return 0;
}
