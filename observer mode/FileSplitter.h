#pragma once
#include<string>
#include<list>

class IProcess
{
public:
    virtual void DoProgress(float vaule) = 0;
    virtual ~IProcess(){}
};

class FileSplitter
{
private:
    std::string m_filePath;
    int m_fileNumber;
    std::list<IProcess*> m_iprocessList;
public:
    FileSplitter(const std::string& filePath,const int fileNumber) : 
        m_filePath(filePath),
        m_fileNumber(fileNumber){}

    void split()
    {
        for(int i = 0;i < m_fileNumber;i++)
        {
            float progressValue = m_fileNumber;
            progressValue = (i + 1) / progressValue;
            onProgress(progressValue);
        }
    }

    void addIProcess(IProcess* iprocess)
    {
        m_iprocessList.emplace_back(iprocess);
    }

    void removeIProcess(IProcess* IProcess)
    {
        m_iprocessList.remove(IProcess);
    }
protected:
    virtual void onProgress(float value)
    {
        std::list<IProcess*>::iterator itor = m_iprocessList.begin();
        while(itor != m_iprocessList.end())
        {
            (*itor)->DoProgress(value);
            ++itor;
        }
    }
};