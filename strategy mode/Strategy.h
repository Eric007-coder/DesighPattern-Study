class Context
{

};

class TaxStrategy;
class StrategyFactory
{
public:
    TaxStrategy* NewStrategy()
    {

    }
};

class TaxStrategy{
public:
    virtual double Caculate(const Context& context) = 0;
    virtual ~TaxStrategy(){}
};

class CNTax : public TaxStrategy{
public:
    virtual double Caculate(const Context& context)
    {

    }
};

class USTax : public TaxStrategy{
public:
    virtual double Caculate(const Context& context)
    {
        
    }
};

class SalesOrder{
private:
    TaxStrategy* strategy;
public:
    SalesOrder(StrategyFactory* strategyFactory)
    {
        this->strategy = strategyFactory->NewStrategy();
    }

    ~SalesOrder()
    {
        delete this->strategy;
    }

    double CaculateTax()
    {
        Context context;
        double val = strategy->Caculate(context);
    }
};