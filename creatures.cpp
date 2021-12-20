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

void Creature::clone(Creature inplace){
    Name = inplace.Name;
    L = inplace.L;
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
bool Creature::is_a_good(){

}

int Creature::threshhold(){
    return L;
}
string Creature::get_creature_name(){
    return Name;
}
/*--------------------------General Creature--------------------------*/

/*--------------------------Good Creature--------------------------*/
good_Creature::good_Creature(int life, string name){
    L = life;
    Name = name;
    is_Good = true;
}

good_Creature::good_Creature(string name){
    Name = name;
    is_Good = true;
}

bool good_Creature::is_a_good(){
    return is_Good;
}
/*--------------------------Good Creature--------------------------*/

/*--------------------------Bad Creature--------------------------*/
bad_Creature::bad_Creature(int life, string name){
    L = life;
    Name = name;
    is_Good = false;
}

bad_Creature::bad_Creature(string name){
    Name = name;
    is_Good = false;
}

bool bad_Creature::is_a_good(){
    return is_Good;
}
/*--------------------------Bad Creature--------------------------*/

/*--------------------------Creature Society--------------------------*/
creature_Society::creature_Society() = default;

creature_Society::creature_Society(int N, int life){
    int i, random;
    for(i = 1; i <= N; i++){
        random = (rand()%10);
        if(random >= 5){
            good_Creature creature(life, random_string());
            Society.add(creature);
        }
        else{
            bad_Creature creature(life, random_string());
            Society.add(creature);
        }
    }
    Size = N;
}

creature_Society::creature_Society(int N){
    int i, random;
    for(i = 1; i <= N; i++){
        random = (rand()%10);
        if(random >= 5){
            good_Creature creature(random_string());
            Society.add(creature);
        }
        else{
            bad_Creature creature(random_string());
            Society.add(creature);
        }
    }
    Size = N;
}

void creature_Society::beat(int position){
    Creature creature = Society.get_data(Society.traverse(position));

    creature.beat();
}

void creature_Society::bless(int position){
    Creature creature = Society.get_data(Society.traverse(position));
    creature.bless();
    if(creature.is_a_good() && creature.threshhold() > (*good_thrsh)){
        clone_next(position);
    }
    else if(creature.threshhold() > (*bad_thrsh)){
        clone_zombies(position);
    }
}
void creature_Society::clone_next(int position){
    Creature creature = Society.get_data(Society.traverse(position));
    position += 1;
    Society.add_in_position(creature, position);
}
void creature_Society::clone_zombies(int position){
    Creature creature = Society.get_data(Society.traverse(position));
    Creature last = Society.get_data(Society.traverse(Size));
    if(creature.get_creature_name() != last.get_creature_name()){
        int i = position +1;
        Creature zcreature;
        for(i; i <= Size; i++){
            zcreature = Society.get_data(Society.traverse(i));
            if(zcreature.is_a_zombie()){
                Society.add_in_position(creature, i);
            }
        }
    }     
}
int creature_Society::no_of_good(){
    int i;
    int number = 0;
    Creature creature;
    for(i = 1; i <= Size; i++){
        creature = Society.get_data(Society.traverse(i));
        if(creature.is_a_good()){
            number++;
        }
    }
    return number;
}
int creature_Society::no_of_zombies(){
    int i;
    int number = 0;
    Creature creature;
    for(i = 1; i <= Size; i++){
        creature = Society.get_data(Society.traverse(i));
        if(creature.is_a_zombie()){
            number++;
        }
    }
    return number;
}
/*--------------------------Creature Society--------------------------*/
