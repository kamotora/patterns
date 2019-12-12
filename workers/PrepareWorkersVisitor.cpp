//
// Created by artem on 07.12.2019.
//

#include "PrepareWorkersVisitor.h"

void PrepareWorkersVisitor::prepare(Manager *worker) {
    worker->preparePacks();
}

void PrepareWorkersVisitor::prepare(Cook *worker) {
    worker->prepareKitchen();
}
void PrepareWorkersVisitor::prepare(Drone *worker) {
    worker->goToCharge();
}
void PrepareWorkersVisitor::prepare(Courier *worker) {
    worker->prepareCar();
}
