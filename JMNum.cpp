#include "JMNum.hpp"

JM::Num::Num()
{
    this->currentType = JMNum;
}

JM::Num::Num(std::string s)
{
    this->currentType = JMNum;
    this->currentValue = std::stod (s);
}

JM::Num::Num(double d)
{
    this->currentType = JMNum;
    this->currentValue = d;
}

JM::Num::~Num()
{

}

double JM::Num::getCurrentValue()
{
    return this->currentValue;
}

JM::Num* JM::Num::add(double d)
{
    return new JM::Num(this->currentValue + d);
}
JM::Num* JM::Num::sub(double d)
{
    return new JM::Num(this->currentValue - d);
}
JM::Num* JM::Num::mul(double d)
{
    return new JM::Num(this->currentValue * d);
}
JM::Num* JM::Num::div(double d)
{
    return new JM::Num(this->currentValue / d);
}
