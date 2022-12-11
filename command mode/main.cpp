#include"Command.h"

int main()
{
    ConcreteCommand1 command1("Arg ###");
    ConcreteCommand2 command2("Arg $$$");
    MacroCommand macro;
    macro.addCommand(&command1);
    macro.addCommand(&command2);
    macro.execute();
    return 0;
}