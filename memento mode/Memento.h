#pragma once
#include<string>

class Memento
{
private:
    std::string state;
public:
    Memento(const std::string& s) : static(s) {}
    std::string getState() const { return state; }
    void setState(const std::string& s) { state = s; }
};

class Originator
{
private:
    std::string state;
public:
    Originator() {}

    Memento createMomento()
    {
        Memento m(state);
        return m;
    }

    void setMomento(const Memento& m)
    {
        state = m.getState();
    }
};