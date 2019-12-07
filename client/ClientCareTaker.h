//
// Created by artem on 04.12.2019.
//

#ifndef PATTERNS_CLIENTCARETAKER_H
#define PATTERNS_CLIENTCARETAKER_H


#include "ClientSnap.h"
#include "stack"
class ClientCareTaker {
private:
    std::stack<ClientSnap *> snaps;
public:
    void save(ClientSnap *snap);
    ClientSnap* restore();
};


#endif //PATTERNS_CLIENTCARETAKER_H
