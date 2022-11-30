#pragma once
#include<vector>

class IDBConnection
{
public:
    virtual void ConnectionString() = 0;
    virtual ~IDBConnection(){}
};

class IDBCommand
{
public:
    virtual void CommandText() = 0;
    virtual void SetConnection() = 0;
    virtual ~IDBCommand(){}
};

class IDataReader
{
public:
    virtual void ExecuteReader() = 0;
    virtual ~IDataReader(){}
};

class IDBFactory
{
public:
    virtual IDBConnection* CreateDBConnection() = 0;
    virtual IDBCommand* CreateDBCommand() = 0;
    virtual IDataReader* CreateDataReader() = 0;
    virtual ~IDBFactory(){}
};

class SqlConnection : public IDBConnection
{
public:
    virtual void ConnectionString()
    {

    }
};

class SqlCommand : public IDBCommand
{
public:
    virtual void CommandText()
    {

    }

    virtual void SetConnection()
    {

    }
};

class SqlDataReader : public IDataReader
{
public:
    virtual void ExecuteReader()
    {

    }
};

class SqlDBFactory : public IDBFactory
{
public:
    virtual IDBConnection* CreateDBConnection()
    {
        return new SqlConnection();
    }

    virtual IDBCommand* CreateDBCommand()
    {
        return new SqlCommand();
    }

    virtual IDataReader* CreateDataReader()
    {
        return new SqlDataReader();
    }
};

class OracleConnection : public IDBConnection
{
public:
    virtual void ConnectionString()
    {

    }
};

class OracleCommand : public IDBCommand
{
public:
    virtual void CommandText()
    {

    }

    virtual void SetConnection()
    {

    }
};

class OracleDataReader : public IDataReader
{
public:
    virtual void ExecuteReader()
    {

    }
};

class OracleDBFactory : public IDBFactory
{
public:
    virtual IDBConnection* CreateDBConnection()
    {
        return new OracleConnection();
    }

    virtual IDBCommand* CreateDBCommand()
    {
        return new OracleCommand();
    }

    virtual IDataReader* CreateDataReader()
    {
        return new OracleDataReader();
    }
};

class EmployeeDAO
{
private:
    IDBFactory* dbFactory;
public:
    EmployeeDAO(IDBFactory* dbFactory)
    {
        this->dbFactory = dbFactory;
    }

    std::vector<EmployeeDAO> GetEmployees()
    {
        IDBConnection* connection = dbFactory->CreateDBConnection();
        connection->ConnectionString();
        IDBCommand* command = dbFactory->CreateDBCommand();
        command->CommandText();
        command->SetConnection();
        IDataReader* reader = dbFactory->CreateDataReader();
        reader->ExecuteReader();
        return std::vector<EmployeeDAO>{};
    }
};