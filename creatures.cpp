#include "randomstring.h"
#include "creatures.h"



int* good_thrsh; //global variables για τα thresholds
int* bad_thrsh;


/*--------------------------General Creature--------------------------*/
Creature::Creature() = default;

Creature::Creature(Creature *old_creature){
    L = old_creature->L;
    Name = old_creature->Name;
}

Creature::Creature(int life, string name){
    L = life;
    Name = name;
}

// void Creature::clone(Creature* replace){
//     this->L = replace->L;
//     this->Name = replace->Name;
// }
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

bool Creature::is_a_zombie(){
    if(L == 0){
        return true;
    }
    else return false;
}

int Creature::threshold(){
    return L;
}

string Creature::get_creature_name(){
    return Name;
}
/*--------------------------General Creature--------------------------*/

/*--------------------------Good Creature--------------------------*/

good_Creature::good_Creature(){
    is_Good = true;
    cout << "Creating good creature" << endl;
}

good_Creature::good_Creature(Creature *old_creature):Creature(*old_creature){
    is_Good = true;
    cout << "Creating good creature" << endl;
}

good_Creature::good_Creature(int life, string name):Creature(life, name){
    is_Good = true;
    cout << "Creating good creature" << endl;
}

bool good_Creature::is_a_good(){
    return is_Good;
}

/*--------------------------Good Creature--------------------------*/

/*--------------------------Bad Creature--------------------------*/

bad_Creature::bad_Creature(){
    is_Good = false;
    cout << "Creating bad creature" << endl;
}

bad_Creature::bad_Creature(Creature *old_creature):Creature(*old_creature){
    is_Good = false;
    cout << "Creating bad creature" << endl;
}

bad_Creature::bad_Creature(int life, string name):Creature(life, name){
    is_Good = false;
    cout << "Creating bad creature" << endl;
}

bool bad_Creature::is_a_good(){
    return is_Good;
}

/*--------------------------Bad Creature--------------------------*/

/*--------------------------Creature Society--------------------------*/

creature_Society::creature_Society(int N, int life){
    int i, random;
    for(i = 1; i <= N; i++){
        random = (rand()%2);
        if(random == 1){
            Creature* creature = new good_Creature(life, random_string()); //create a new good creature 
            Society.add(creature); //add the creature in the creature society
        }
        else{
            Creature* creature = new bad_Creature(life, random_string()); //create a new bad creature 
            Society.add(creature); //add the creature in the creature society
        }
        Size++;
    }
    cout << "Created creature society" << endl;
}

creature_Society::~creature_Society(){
    while(Size > 0){
        Creature* rcreature = Society.get_data(Society.traverse(Size));
        delete rcreature;
        Size--;
    }
    cout << "Deleted creature society" << endl;
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
    if(creature->is_a_zombie() == false){
        if(creature->is_a_good() && creature->threshold() > (*good_thrsh)){
            clone_next(position);
        }
        else if(creature->threshold() > (*bad_thrsh)){
            clone_zombies(position);
        }
    }
}
void creature_Society::clone_next(int position){
    if(position != Size){
        Creature* cloned = Society.get_data(Society.traverse(position)); 
        position += 1;
        Creature* removed = Society.get_data(Society.traverse(position)); 
        delete removed;
        if(cloned->is_a_good()){
            Creature* clone = new good_Creature(cloned);
            //clone->clone(cloned);
            Society.add_in_position(clone, position);
        }
        else{
            Creature* clone = new bad_Creature(cloned);
            //clone->clone(cloned);
            Society.add_in_position(clone, position);
        }
    cout << "Cloning creature in position " << position-1 << endl;
    }
}
    
void creature_Society::clone_zombies(int position){
    if(position != Size){
        Creature* cloned = Society.get_data(Society.traverse(position));
        int i = position + 1;
        Creature* zcreature;
        for(i; i <= Size; i++){
            zcreature = Society.get_data(Society.traverse(i));
            if(zcreature->is_a_zombie()){
                delete zcreature;
                if(cloned->is_a_good()){
                    Creature* clone = new good_Creature(cloned);
                    //clone->clone(cloned);
                    Society.add_in_position(clone, i);
                    cout << "Cloning creature in position " << position << endl;
                }
                else{
                    Creature* clone = new bad_Creature(cloned);
                    //clone->clone(cloned);
                    Society.add_in_position(clone, i);
                    cout << "Cloning creature in position " << position << endl;
                }
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

void creature_Society::print(){
    for(int i = 1; i <= Society.get_size(); i++){
        Creature* creature = Society.get_data(Society.traverse(i));
        cout << "Creature in memory address: " << creature << " is named " << creature->get_creature_name() << " his HP is " << creature->threshold()
        << " good: " << creature->is_a_good() << " zombie: " << creature->is_a_zombie() << endl;
    }
}
/*--------------------------Creature Society--------------------------*/
