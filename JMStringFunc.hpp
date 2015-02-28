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
        JM::String* evaluateStringMethod(JM::String* obj, std::string function, std::vector<JM::Object*> params);
        JM::Num* evaluateNumMethod(JM::Object* obj, std::string function, std::vector<JM::Object*> params);

    };

};

#endif
