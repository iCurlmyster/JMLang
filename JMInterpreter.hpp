#ifndef JMINTERPRETER_HPP
#define JMINTERPRETER_HPP

namespace JM {

    class Interpreter {

    public:
        Interpreter();
        ~Interpreter();

         void interpret(JM::Parser& parser,Map<std::string,JM::Object>& vars,JMType type);    

    };

};


#endif
