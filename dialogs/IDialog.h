//
// Created by artem on 26.11.2019.
//

#ifndef PATTERNS_IDIALOG_H
#define PATTERNS_IDIALOG_H

class IOrder;
class IDialog {
public:
    virtual IOrder * showDialog() = 0;
};


#endif //PATTERNS_IDIALOG_H
