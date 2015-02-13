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
        vector<string> printVec;

        if (printType == JMString) printVec = parser.returnParsedString();
        if (printType == JMVar)
        {

            vector<string> varvec = parser.returnParsedString();

            JM::String* strTemp = (JM::String*)(variables[(parser.returnParsedString())[0]]);

             printVec.push_back(strTemp->getCurrentValue());
        }
        //if (printType == JMError) { cout<<"Error on line: "<<lineNumber<<endl; printVec.push_back(""); }
        else printVec.push_back(lineString[1]);
         print(printVec[0]);
    }
    if (lineString[0] == "println")
    {
        JMType printType = parser.evaluateParse(lineString[1]);
        vector<std::string> printVec;

        if (printType == JMString) printVec = parser.returnParsedString();
        //else if (printType == JMError) cout<<"Error on line: "<<lineNumber<<endl;
        else if (printType == JMVar)
        {

            vector<string> varvec = parser.returnParsedString();

            JM::String* strTemp = (JM::String*)(variables[(parser.returnParsedString())[0]]);

            printVec.push_back(strTemp->getCurrentValue());
        }
        else printVec.push_back(lineString[1]);
         println(printVec[0]);
    }
}
