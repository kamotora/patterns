//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_GOOD_H
#define PATTERNS_GOOD_H

#include <string>
using namespace std;

class Good {
protected:
    double cost;
    string name;
public:
    const string &getName() const;

    void setName(const string &name);

    double getCost() const;

    void setCost(double cost);
};


#endif //PATTERNS_GOOD_H
