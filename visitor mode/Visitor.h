#pragma once
#include<iostream>

class Visitor;
class Element
{
public:
    virtual void accept(Visitor& visitor) = 0;
    virtual ~Element() {}
};

class ElementA;
class ElementB;
class Visitor
{
public:
    virtual void visitElementA(ElementA& element) = 0;
    virtual void visitElementB(ElementB& element) = 0;
    virtual ~Visitor() {}
};

class ElementA : public Element
{
public:
    virtual void accept(Visitor& visitor)
    {
        visitor.visitElementA(*this);
    }
};

class ElementB : public Element
{
public:
    virtual void accept(Visitor& visitor)
    {
        visitor.visitElementB(*this);
    }
};

class Visitor1 : public Visitor
{
public:
    virtual void visitElementA(ElementA& element)
    {
        std::cout << "Visitor1 is processing ElementA" << std::endl;
    }

    virtual void visitElementB(ElementB& element)
    {
        std::cout << "Visitor1 is processing ElementB" << std::endl;
    }
};

class Visitor2 : public Visitor
{
public:
    virtual void visitElementA(ElementA& element)
    {
        std::cout << "Visitor2 is processing ElementA" << std::endl;
    }

    virtual void visitElementB(ElementB& element)
    {
        std::cout << "Visitor2 is processing ElementB" << std::endl;
    }
};