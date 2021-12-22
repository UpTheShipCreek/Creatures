#include "randomstring.h"
#include "creatures.h"



int* good_thrsh;
int* bad_thrsh;


/*--------------------------General Creature--------------------------*/
Creature::Creature() = default;

Creature::Creature(string name){
    Name = name;
}

Creature::Creature(int life, string name){
    L = life;
    Name = name;
}

void Creature::clone(Creature* replace){
    Name = replace->Name;
    L = replace->L;
}
void Creature::bless(){
    if(is_a_zombie() == false){
        L++;
    }
}
void Creature::beat(){
    if(is_a_zombie() == false){
        L--;
    }
}
void Creature::set_life(int life){
    L = life;
}

bool Creature::is_a_zombie(){
    if(L == 0){
        return true;
    }
    else return false;
}

int Creature::threshhold(){
    return L;
}

void Creature::add_creature_information(int life, string name){
    L = life;
    Name = name;
}

string Creature::get_creature_name(){
    return Name;
}
/*--------------------------General Creature--------------------------*/

/*--------------------------Good Creature--------------------------*/

// good_Creature::good_Creature(int life, string name){
//     L = life;
//     Name = name;
//     is_Good = true;
// }

good_Creature::good_Creature(){
    is_Good = true;
}

bool good_Creature::is_a_good(){
    return is_Good;
}
/*--------------------------Good Creature--------------------------*/

/*--------------------------Bad Creature--------------------------*/

// bad_Creature::bad_Creature(int life, string name){
//     L = life;
//     Name = name;
//     is_Good = false;
// }

bad_Creature::bad_Creature(){
    is_Good = false;
}

bool bad_Creature::is_a_good(){
    return is_Good;
}
/*--------------------------Bad Creature--------------------------*/

/*--------------------------Creature Society--------------------------*/
creature_Society::creature_Society() = default;

// creature_Society::~creature_Society(){
//     while(Size > 0){
//         Creature* rcreature = Society.get_data(Society.traverse(Size));
//         delete rcreature;
//         Size--;
//     }
// }

creature_Society::creature_Society(int N, int life){
    int i, random;
    for(i = 1; i <= N; i++){
        random = (rand()%2);
        if(random == 1){
            Creature* creature = new good_Creature();
            creature->add_creature_information(life, random_string());
            Society.add(creature);
            cout << "Adding good creature" << endl;
        }
        else{
            Creature* creature = new bad_Creature();
            creature->add_creature_information(life, random_string());
            Society.add(creature);
            cout << "Adding bad creature" << endl;
        }
        Size++;
    }
}

creature_Society::creature_Society(int N){
    int i, random;
    for(i = 1; i <= N; i++){
        random = (rand()%2);
        if(random >= 1){
            Creature* creature = new good_Creature();
            Society.add(creature);
        }
        else{
            Creature* creature = new bad_Creature();
            Society.add(creature);
        }
        Size++;
    }
}

void creature_Society::beat(int position){
    Creature* creature = Society.get_data(Society.traverse(position));
    cout << "Beating creature in position " << position << endl;
    creature->beat();
}

void creature_Society::bless(int position){
    Creature* creature = Society.get_data(Society.traverse(position));
    cout << "Blessing creature in position " << position << endl;
    creature->bless();
    if(creature->is_a_good() && creature->threshhold() > (*good_thrsh)){
        clone_next(position);
    }
    else if(creature->threshhold() > (*bad_thrsh)){
        clone_zombies(position);
    }
}
void creature_Society::clone_next(int position){
    Creature* cloned = Society.get_data(Society.traverse(position)); 
    position += 1;
    // Creature* removed = Society.get_data(Society.traverse(position)); 
    // delete removed;
    Society.add_in_position(cloned, position);
}
void creature_Society::clone_zombies(int position){
    Creature* creature = Society.get_data(Society.traverse(position));
    Creature* last = Society.get_data(Society.traverse(Society.get_size()));
    if(creature->get_creature_name() != last->get_creature_name()){
        int i = position +1;
        Creature* zcreature;
        for(i; i <= Size; i++){
            zcreature = Society.get_data(Society.traverse(i));
            if(zcreature->is_a_zombie()){
                //delete zcreature;
                Society.add_in_position(creature, i);
            }
        }
    }     
}
int creature_Society::no_of_good(){
    int i;
    int number = 0;
    Creature* creature;
    for(i = 1; i <= Size; i++){
        creature = Society.get_data(Society.traverse(i));
        if(creature->is_a_good() && (!creature->is_a_zombie())){
            number++;
        }
    }
    return number;
}
int creature_Society::no_of_zombies(){
    int i;
    int number = 0;
    Creature* creature;
    for(i = 1; i <= Size; i++){
        creature = Society.get_data(Society.traverse(i));
        if(creature->is_a_zombie()){
            number++;
        }
    }
    return number;
}
/*--------------------------Creature Society--------------------------*/
