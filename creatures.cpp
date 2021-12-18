#include <iostream>
#include <random>
#include <string.h>
#include "clist.h"


using namespace std;
#define good_thrsh 10
#define bad_thrsh 10

class Creature{
    string Name;
    int L;

    public:
    Creature() = default;

    void clone(Creature inplace){
        Name = inplace.Name;
        L = inplace.L;
    }
    void bless(){
        if(is_a_zombie() == false){
            L++;
        }
    }
    void beat(){
        if(is_a_zombie() == false){
            L--;
        }
    }

    bool is_a_good();

    bool is_a_zombie(){
        if(L == 0){
            return true;
        }
        else return false;
    }
    int threshhold(){
        return L;
    }

    void initialize(int life, string name){
        L = life;
        Name = name;
    }

    string get_creature_name(){
        return Name;
    }
};

class good_Creature: public Creature{
    
    bool is_Good;

    public:
    good_Creature(){
        is_Good = true;
    }

    bool is_a_good(){
        return is_Good;
    }
    void bless(){

    }
};

class bad_Creature: public Creature{
    bool is_Good;

    public:
    bad_Creature(){
        is_Good = false;
    }

    bool is_a_good(){
        return is_Good;
    }
};

class creature_society{
    cyList<Creature> Society;
    int Size;

    public:
    creature_society(int N){
        int i, random;
        for(i = 1; i <= N; i++){
            random = (rand()%10);
            if(random >= 5){
                good_Creature creature;
                Society.add(creature);
            }
            else{
                bad_Creature creature;
                Society.add(creature);
            }
        }
        Size = N;
    }
    void beat(int position){
        Creature creature = Society.get_data(Society.traverse(position));

        creature.beat();
    }

    void bless(int position){
        Creature creature = Society.get_data(Society.traverse(position));
        creature.bless();
        if(creature.is_a_good() && creature.threshhold() > good_thrsh){
            clone_next(position);
        }
        else if(creature.threshhold() > bad_thrsh){
            clone_zombies(position);
        }
    }
    void clone_next(int position){
        Creature creature = Society.get_data(Society.traverse(position));
        position += 1;
        Society.add_in_position(creature, position);
    }
    void clone_zombies(int position){
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
    int no_of_good(){
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
    int no_of_zombies(){
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
};