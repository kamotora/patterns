//
// Created by artem on 07.12.2019.
//

#ifndef PATTERNS_IVISITORELEMENT_H
#define PATTERNS_IVISITORELEMENT_H


class IVisitor;
class IVisitorElement {
public:
    virtual void accept(IVisitor *visitor) = 0;
};


#endif //PATTERNS_IVISITORELEMENT_H
