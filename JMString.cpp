#include "JMString.hpp"
#include <iostream>

JM::String::String()
{
    this->currentType = JMString;
}

JM::String::String(std::string s)
{
    this->currentType = JMString;
    this->currentValue = s;
}

JM::String::~String()
{

}

void JM::String::setCurrentValue(std::string s)
{
    this->currentValue = s;
}

std::string JM::String::getCurrentValue()
{
    return this->currentValue;
}

std::string JM::String::concatenate(JM::String* obj)
{
    return this->currentValue + obj->getCurrentValue();
}
