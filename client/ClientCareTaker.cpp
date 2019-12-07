//
// Created by artem on 04.12.2019.
//

#include "ClientCareTaker.h"

void ClientCareTaker::save(ClientSnap *snap) {
    snaps.push(snap);
}

ClientSnap *ClientCareTaker::restore() {
    ClientSnap * res = snaps.top();
    snaps.pop();
    return res;
}
