#include <string>
#include <iostream>
#include "clist.h"

using namespace std;

class Creature{
    string Name;
    int L;

    public:
    Creature();
    Creature(Creature *old_creature);
    Creature(string name);
    Creature(int life, string name);
    // void clone(Creature* replace);
    void bless();
    void beat();
    bool virtual is_a_good() = 0;; //pure virtual
    bool is_a_zombie();
    int threshold();
    string get_creature_name();
    void add_creature_information(int life, string name);
};

class good_Creature:public Creature{
    bool is_Good;

    public:
    good_Creature(int life, string name);
    good_Creature(Creature *old_creature);
    good_Creature();
    bool is_a_good();
};

class bad_Creature:public Creature{
    bool is_Good;

    public:
    bad_Creature(int life, string name);
    bad_Creature(Creature *old_creature);
    bad_Creature();
    bool is_a_good();
};

class creature_Society{
    cyList<Creature> Society;
    int Size;

    public:
    creature_Society();
    ~creature_Society();
    creature_Society(int N, int life);
    creature_Society(int N);
    void beat(int position);
    void bless(int position);
    void clone_next(int position);
    void clone_zombies(int position);
    int no_of_good();
    int no_of_zombies();
    void print();
};