#include "JMInterpreter.hpp"
#include "JMGlobalFunctions.h"


JM::Interpreter::Interpreter()
{

}

JM::Interpreter::~Interpreter()
{

}

void JM::Interpreter::interpret(JM::Parser& parser, JMType type)
{

    if (type == JMFunc)
    {
        this->func(parser);
    }
    if (type == JMAssign)
    {
        this->assign(parser);
    }

}

void JM::Interpreter::assign(JM::Parser& parser)
{
    vector<string> lineString = parser.returnParsedString();
    if( lineString.size() > 0){

        JMType assignType = parser.evaluateParse(lineString[2]);

        if (assignType == JMString)
        {
            vector<string> printVec = parser.returnParsedString();
            JM::String *strObj = new JM::String(printVec[0]);
            variables[lineString[1]] = strObj;
        }
        else if (assignType == JMNum)
        {
            vector<string> printVec = parser.returnParsedString();
            JM::Num *numObj = new JM::Num(printVec[0]);
            variables[lineString[1]] = numObj;
        }
        else {
            cout<<"Not a string\n";
        }
    }
    else
    {
        cout<<"Not formatted correctly for assignment.\n";
    }
}

void JM::Interpreter::func(JM::Parser& parser)
{
    vector<string> lineString = parser.returnParsedString();
    if (lineString[0] == "print")
    {
        JMType printType = parser.evaluateParse(lineString[1]);
        JM::Object* temp = handleInterpret(parser,printType,lineString[1]);

        if (temp != NULL)
        {
            if (temp->getCurrentType() == JMString)
            {
                auto tempVal = ((JM::String*)temp)->getCurrentValue();
                print(tempVal);
            }
            else if (temp->getCurrentType() == JMNum)
            {
                auto tempVal = ((JM::Num*)temp)->getCurrentValue();
                print(std::to_string(tempVal));
            }
        }
        else
        {
            std::cout<<"Object was NULL\n";
        }
    }
    if (lineString[0] == "println")
    {
        JMType printType = parser.evaluateParse(lineString[1]);
        JM::Object* temp = handleInterpret(parser,printType,lineString[1]);

        if (temp != NULL)
        {
            if (temp->getCurrentType() == JMString)
            {
                auto tempVal = ((JM::String*)temp)->getCurrentValue();
                println(tempVal);
            }
            else if (temp->getCurrentType() == JMNum)
            {
                auto tempVal = ((JM::Num*)temp)->getCurrentValue();
                println(std::to_string(tempVal));
            }
        }
        else
        {
            std::cout<<"Object was NULL\n";
        }

    }
}

JM::Object* JM::Interpreter::getVariable(string s)
{
    return variables[s];
}

JM::Object* JM::Interpreter::handleInterpret(JM::Parser& parser,JMType type, string line)
{

    JM::Object* temp = NULL;
    if (type == JMString) temp = new JM::String( (parser.returnParsedString())[0] );
    else if (type == JMNum) temp = new JM::Num((parser.returnParsedString())[0]);
    else if (type == JMVar)
    {
        temp = variables[(parser.returnParsedString())[0]];
    }
    else temp = new JM::String("");
    return temp;
}
