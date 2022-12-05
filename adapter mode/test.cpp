#include"Adapter.h"

int main()
{
    IAdaptee* pAdaptee = new OldClass();
    ITarget* pTarget = new Adapter(pAdaptee);
    pTarget->process();
    return 0;
}