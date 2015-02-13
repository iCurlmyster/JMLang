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

JM::Num::~Num()
{

}

double JM::Num::getCurrentValue()
{
    return this->currentValue;
}

double JM::Num::add(JM::Num *n)
{
    return this->currentValue + n->getCurrentValue();
}
double JM::Num::sub(JM::Num *n)
{

}
double JM::Num::mul(JM::Num *n)
{

}
double JM::Num::div(JM::Num *n)
{

}
double JM::Num::mod(JM::Num *n)
{

}
