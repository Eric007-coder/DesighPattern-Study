#pragma once
#include<string>
#include<iostream>
#include<vector>

class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

class ConcreteCommand1 : public Command
{
private:
    std::string arg;
public:
    ConcreteCommand1(const std::string& a) : arg(a) {}

    virtual void execute()
    {
        std::cout << "#1 process..." << arg << std::endl;
    }
};

class ConcreteCommand2 : public Command
{
private:
    std::string arg;
public:
    ConcreteCommand2(const std::string& a) : arg(a) {}

    virtual void execute()
    {
        std::cout << "#2 process..." << arg << std::endl;
    }
};

class MacroCommand : public Command
{
private:
    std::vector<Command*> commands;
public:
    void addCommand(Command* c)
    {
        commands.push_back(c);
    }

    virtual void execute()
    {
        for(auto& c : commands)
            c->execute();
    }
};