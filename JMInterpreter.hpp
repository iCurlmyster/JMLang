#ifndef JMINTERPRETER_HPP
#define JMINTERPRETER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <map>
#include "JMObject.hpp"
#include "JMParser.hpp"
#include "JMNum.hpp"
#include "JMString.hpp"
#include "JMMethodCall.hpp"

using namespace std;

namespace JM {

    class Interpreter {

        map<string, JM::Object*> variables;
        JM::MethodCall methodCalls;

    public:

        Interpreter();
        ~Interpreter();

         void interpret(JM::Parser& parser, JMType type);

         void assign(JM::Parser& parser);
         void func(JM::Parser& parser);
         JM::Object* method(JM::Parser& parser);

         JM::Object* getVariable(string s);

         JM::Object* handleInterpret(JM::Parser& parser,JMType type);

    };


};


#endif