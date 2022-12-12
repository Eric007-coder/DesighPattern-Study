#pragma once
#include<map>
#include<iostream>
#include<stack>

class Expression
{
public:
    virtual int interpreter(std::map<char,int> var) = 0;
    virtual ~Expression() {}
};

class VarExpression : public Expression
{
private:
    char key;
public:
    VarExpression(const char& key)
    {
        this->key = key;
    }

    virtual int interpreter(std::map<char,int> var)
    {
        return var[key];
    }
};

class SymbolExpression : public Expression
{
protected:
    Expression* left;
    Expression* right;
public:
    SymbolExpression(Expression* left,Expression* right) : left(left),right(right) {}
};

class AddExpression : public SymbolExpression
{
public:
    AddExpression(Expression* left,Expression* right) : SymbolExpression(left,right) {}

    virtual int interpreter(std::map<char,int> var)
    {
        return left->interpreter(var) + right->interpreter(var);
    }
};

class SubExpression : public SymbolExpression
{
public:
    SubExpression(Expression* left,Expression* right) : SymbolExpression(left,right) {}

    virtual int interpreter(std::map<char,int> var)
    {
        return left->interpreter(var) - right->interpreter(var);
    }
};

Expression* analyse(std::string expStr)
{
    std::stack<Expression*> expStack;
    Expression* left = nullptr;
    Expression* right = nullptr;
    for(int i = 0;i < expStr.length();++i)
    {
        switch(expStr[i])
        {
            case '+':
                left = expStack.top();
                right = new VarExpression(expStr[++i]);
                expStack.push(new AddExpression(left,right));
                break;
            case '-':
                left = expStack.top();
                right = new VarExpression(expStr[++i]);
                expStack.push(new SubExpression(left,right));
                break;
            default:
                expStack.push(new VarExpression(expStr[i]));
        }
    }
    Expression* expression = expStack.top();
    return expression;
}