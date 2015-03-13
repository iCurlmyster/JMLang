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

JM::String* JM::String::concatenate(JM::String* obj)
{
    return new JM::String(this->currentValue + obj->getCurrentValue());
}

JM::String* JM::String::concatenate(std::string s)
{
    return new JM::String(this->currentValue + s);
}
std::string JM::String::toString() const
{
    return this->currentValue;
}
