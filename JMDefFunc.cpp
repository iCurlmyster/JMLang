#include "JMDefFunc.hpp"
#include <iostream>

JM::DefFunc::DefFunc() {
    currentType = JMDefFunc;
}

JM::DefFunc::~DefFunc() {

}

void JM::DefFunc::setParameters(std::vector<std::string> par)
{
    parameters = par;
}
void JM::DefFunc::setOperations(std::vector<std::string> op)
{
    operations = op;
}
std::vector<std::string> JM::DefFunc::getParameters()
{
    return parameters;
}
std::vector<std::string> JM::DefFunc::getOperations()
{
    return operations;
}

std::string JM::DefFunc::toString() const
{
    std::string str = "";
    str += "{ [";
    if (parameters.size() > 0) str += parameters[0];
    for(int i = 1; i< parameters.size(); i++)
    {
        str += ", " + parameters[i];
    }
    str += "] : ";
    str += operations[0];
    for(int i = 1; i<operations.size();++i)
    {
        str += ", " + operations[i];
    }
    str += " }";
    return str;
}
