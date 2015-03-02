#ifndef JMMETHOD_CALL
#define JMMETHOD_CALL

#include "JMObject.hpp"
#include "JMString.hpp"
#include "JMNum.hpp"
#include <vector>
#include <string>

namespace JM {

    class MethodCall {

    public:
        MethodCall();
        ~MethodCall();
        JM::Object* evaluateStringMethod(JM::String* obj, std::string function, std::vector<JM::Object*>& params);
        JM::Object* evaluateNumMethod(JM::Num* obj, std::string function, std::vector<JM::Object*>& params);

    };

};

#endif
