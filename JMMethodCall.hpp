#ifndef JMMETHOD_CALL
#define JMMETHOD_CALL

#include "JMFiles.hpp"
#include "FileManager.hpp"
#include <vector>
#include <string>
#include <map>

namespace JM {

    class MethodCall {

        FileManager manager;

    public:
        MethodCall();
        ~MethodCall();
        JM::Object* evaluateStringMethod(JM::String* obj, std::string function, std::vector<JM::Object*>& params);
        JM::Object* evaluateNumMethod(JM::Num* obj, std::string function, std::vector<JM::Object*>& params);
        JM::Object* evaluateArrayMethod(JM::Array* obj, std::string function, std::vector<JM::Object*>& params);
        JM::Object* evaluateDefFuncMethod(JM::DefFunc* obj, std::string function, std::vector<JM::Object*>& params);

    };

};

#endif
