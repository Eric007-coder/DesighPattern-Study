#include"Visitor.h"

int main()
{
    Visitor2 visitor;
    ElementB elementB;
    elementB.accept(visitor);
    ElementA elementA;
    elementA.accept(visitor);
    return 0;
}