//
// Created by root on 24.10.2019.
//

#ifndef PATTERNS_PRODUCT_H
#define PATTERNS_PRODUCT_H

#include <string>
#include <vector>

using namespace std;

class Product{
private:
    double saleCost;
protected:
    string name;
public:
    Product() = default;
    Product(double saleCost);
    Product(string name, double saleCost);
    const string &getName() const;

    void setName(const string &name);

    virtual double getSaleCost() const;

    virtual void setSaleCost(double cost);

    virtual double getPrimeCost() const;
    virtual vector<pair<Product *, int>> * getChild();

};


#endif //PATTERNS_PRODUCT_H
