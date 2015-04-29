#ifndef JMINTERPRETER_HPP
#define JMINTERPRETER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <map>
#include "JMFiles.hpp"
#include "JMParser.hpp"
#include "JMMethodCall.hpp"

using namespace std;

namespace JM {

    class Interpreter {

        /**
        * Map to hold variables that are created.
        * Key: std::string
        * Value: JM::Object*
        */
        map<string, JM::Object*> *variables;

        /**
        * MethodCall object to handle method calling
        */
        JM::MethodCall methodCalls;

    public:

        Interpreter(map<string, JM::Object*> *variables);
        ~Interpreter();

         JM::Object* interpret(JM::Parser& parser, JMType type);

         void add_variable(std::string &str, JM::Object* obj);
         void assign(JM::Parser& parser);
         void func(JM::Parser& parser);
         JM::Object* method(JM::Parser& parser);

         JM::Object* handleInterpret(JM::Parser& parser,JMType type);

    };


};


#endif
