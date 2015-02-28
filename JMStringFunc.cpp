#include "JMStringFunc.hpp"

#include <iostream>

JM::MethodCall::MethodCall() {

}

JM::MethodCall::~MethodCall() {

}

JM::String* JM::MethodCall::evaluateStringMethod(JM::String* obj, std::string function, std::vector<JM::Object*> params)
{

    if (function == "concat")
    {

        std::string temp;
        for (int i = 0; i < params.size(); i++)
        {
            if (params[i]->getCurrentType() == JMString)
                temp = temp + ((JM::String*)params[i])->getCurrentValue();
            else if (params[i]->getCurrentType() == JMNum)
                temp = temp + std::to_string( ((JM::String*)params[i])->getCurrentType() );
        }

        return obj->concatenate(temp);

    }

    return NULL;
}

JM::Num* JM::MethodCall::evaluateNumMethod(JM::Object* obj, std::string function, std::vector<JM::Object*> params)
{


    return NULL;
}
