#include"Expression.h"

int main()
{
    std::string expStr = "a+b-c+d-e";
    std::map<char,int> var;
    var.insert(std::make_pair('a',5));
    var.insert(std::make_pair('b',2));
    var.insert(std::make_pair('c',1));
    var.insert(std::make_pair('d',6));
    var.insert(std::make_pair('e',10));
    Expression* expression = analyse(expStr);
    std::cout << expression->interpreter(var) << std::endl;
    return 0;
}