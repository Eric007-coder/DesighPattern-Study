#pragma once
#include<iostream>

class ITarget
{
public:
    virtual void process() = 0;
};

class IAdaptee
{
public:
    virtual void foo(int data) = 0;
    virtual int bar() = 0;
};

class OldClass : public IAdaptee
{
public:
    virtual void foo(int data)
    {
        std::cout << data << std:: endl;
    }

    virtual int bar()
    {
        return 7;
    }
};

class Adapter : public ITarget
{
protected:
    IAdaptee* pAdaptee;
public:
    Adapter(IAdaptee* pAdaptee)
    {
        this->pAdaptee = pAdaptee;
    }

    virtual void process()
    {
        int data = pAdaptee->bar();
        pAdaptee->foo(data);
    }
};