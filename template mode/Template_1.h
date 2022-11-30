#pragma once
#include<iostream>

class Library{
public:
    void Run()
    {
        Step1();
        
        if(Step2())
            Step3();
        
        for(int i = 0;i < 4;i++)
            Step4();
        
        Step5();
    }

    virtual ~Library(){}
protected:
    void Step1()
    {
        std::cout << "1" << std::endl;
    }

    void Step3()
    {
        std::cout << "3" << std::endl;
    }

    void Step5()
    {
        std::cout << "5" << std::endl;
    }

    virtual bool Step2() = 0;
    virtual void Step4() = 0;
};