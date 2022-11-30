#include"template_2.h"

int main()
{
    Library* p = new Application();
    p->Run();
    delete p;
    return 0;
}