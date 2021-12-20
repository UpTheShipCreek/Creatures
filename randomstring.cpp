#include <string>
#include <random>
#include "randomstring.h"

std::string random_string() {
    static const char alphanum[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    int len = (rand() % 10 + 1);
    std::string temp;
    temp.reserve(len);

    for (int i = 0; i < len; i++) {
        temp += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return temp;
}
