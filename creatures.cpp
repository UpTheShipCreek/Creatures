#include <iostream>

using namespace std;

class creature{
    string Name;
    int L;

    public:
    creature() = default;
    void clone(creature inplace){
        Name = inplace.Name;
        L = inplace.L;
    }
    void bless(){
        L++;
    }
    void beat(){
        L--;
    }
};
