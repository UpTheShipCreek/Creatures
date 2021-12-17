#include <iostream>

using namespace std;
#define good_thrsh 10
#define bad_thresh 10

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
    bool is_a_zombie(){
        if(L == 0){
            return true;
        }
        else return false;
    }
    int threshhold(){
        return L;
    }
};

class good_Creature: public Creature{
    bool is_a_good(){
        return true;
    }
    void bless(){

    }
};

class bad_Creature: public Creature{
    bool is_a_good(){
        return false;
    }
};

class creature_society{
    
};