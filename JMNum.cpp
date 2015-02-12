#include "JMNum.hpp"

JM::Num::Num()
{
    this->currentType = JMNum;
}

JM::Num::Num(std::string s)
{
    this->currentType = JMNum;
    this->currentValue = (double)s;
}

JM::Num::~Num()
{

}

double JM::Num::getCurrentValue()
{
    return this->currentValue;
}
