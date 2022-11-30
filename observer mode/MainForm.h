#pragma once
#include"FileSplitter.h"
#include<iostream>

class Form
{

};

class TextBox
{
public:
    std::string getText()
    {

    }
};

class ProgressBar
{
public:
    void setValue(int value)
    {
        
    }
};

class MainForm : public Form,public IProcess
{
private:
    TextBox* txtFilePath;
    TextBox* txtFileNumber;
    ProgressBar* progressBar;
public:
    void Button_Click()
    {
        std::string filePath = txtFilePath->getText();
        int number = atoi(txtFileNumber->getText().c_str());
        ConsoleNotifier cn;
        FileSplitter splitter(filePath,number);
        splitter.addIProcess(this);
        splitter.addIProcess(&cn);
        splitter.split();
        splitter.removeIProcess(this);
    }

    virtual void DoProgress(float value)
    {
        progressBar->setValue(value);
    }
};

class ConsoleNotifier : public IProcess
{
public:
    virtual void DoProgress(float value)
    {
        std::cout << ".";
    }
};