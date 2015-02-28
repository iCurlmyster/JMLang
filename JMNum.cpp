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

JM::Num* JM::Num::add(JM::Num *n)
{
    return new JM::Num(this->currentValue + n->getCurrentValue());
}
JM::Num* JM::Num::sub(JM::Num *n)
{
    return new JM::Num(this->currentValue - n->getCurrentValue());
}
JM::Num* JM::Num::mul(JM::Num *n)
{
    return new JM::Num(this->currentValue * n->getCurrentValue());
}
JM::Num* JM::Num::div(JM::Num *n)
{
    return new JM::Num(this->currentValue / n->getCurrentValue());
}
