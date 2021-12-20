#include <string>
#include <iostream>
#include "clist.h"

using namespace std;

class Creature{
    // string Name;
    // int L;

    public:
    string Name;
    int L;
    Creature();
    Creature(string name);
    Creature(int life, string name);
    void clone(Creature inplace);
    void bless();
    void beat();
    void set_life(int life);
    bool is_a_good(); //just so it can be called 
    bool is_a_zombie();
    int threshhold();
    string get_creature_name();
};

class good_Creature: public Creature{
    bool is_Good;

    public:
    good_Creature(int life, string name);
    bool is_a_good();
};

class bad_Creature: public Creature{
    bool is_Good;

    public:
    bad_Creature(int life, string name);
    bool is_a_good();
};

class creature_Society{
    cyList<Creature> Society;
    int Size;

    public:
    creature_Society();
    creature_Society(int N, int life);
    creature_Society(int N);
    void beat(int position);
    void bless(int position);
    void clone_next(int position);
    void clone_zombies(int position);
    int no_of_good();
    int no_of_zombies();
};