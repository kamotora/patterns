//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_GOOD_H
#define PATTERNS_GOOD_H

#include <string>
using namespace std;

class Good {
private:
    string name;
public:
    const string &getName() const;

    void setName(const string &name);
};


#endif //PATTERNS_GOOD_H
