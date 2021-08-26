#include <iostream>
using namespace std;


class Hotel{
public:
    int room_num;
    float cost;

    Hotel(int room_num, float cost){
        room_num = room_num;
        cost = cost;
    }
};

class Services:public Hotel{
public:
    int night_cost;
    int night_num;
    int dry_cleaning_cost;
    int spa_cost;


    Services(int room_num,float cost, int night_cost,int night_num,int dry_cleaning_cost,int spa_cost)
        :Hotel(room_num , cost)
    {
        night_cost = night_cost;
        night_num = night_num;
        dry_cleaning_cost = dry_cleaning_cost;
        spa_cost = spa_cost;
    }
};

class Guest{
public:
    string monster_or_human;
    string name;
    string new_or_old;
    int id;

    /*Guest(string monster_or_human,string name, int id){
        monster_or_human = monster_or_human;
        name = name;
        id = id;
    }*/

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
        cout << "Dear " + monster_or_human +" " + name + ", Your id is: " << id << endl;
    }
};


/*class Monster:public Guest{
public:
    string name;

    Monster(string monster_or_human, int id, string name)
            :Guest(monster_or_human, id)
    {
        name = name;
    }
};
*/

int main() {

    Guest guest1;
    guest1.ask_new_or_old();

    if (guest1.new_or_old == "new")
    {
        guest1.create_account();
        guest1.display_id();
    }
    else if (guest1.new_or_old == "old")
    {
        guest1.ask_for_id();
    }

    return 0;
}
