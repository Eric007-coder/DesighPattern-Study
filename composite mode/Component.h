#pragma once
#include<string>
#include<list>
#include<iostream>

class Component
{
public:
    virtual void process() = 0;
    virtual ~Component() {}
};

class Composite : public Component
{
private:
    std::string name;
    std::list<Component*> elements;
public:
    Composite(const std::string& s) : name(s) {}

    void add(Component* element)
    {
        elements.push_back(element);
    }

    void remove(Component* element)
    {
        elements.remove(element);
    }

    void process()
    {
        std::cout << "processing " << name << std::endl;
        for(auto& e : elements)
            e->process();
    }
};

class Leaf : public Component
{
private:
    std::string name;
public:
    Leaf(std::string s) : name(s) {}

    void process()
    {
        std::cout << "processing " << name << std::endl;
    }
};

void Invoke(Component& c)
{
    c.process();
}