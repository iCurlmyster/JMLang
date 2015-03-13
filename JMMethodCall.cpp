#include "JMMethodCall.hpp"

#include <iostream>

JM::MethodCall::MethodCall() {

}

JM::MethodCall::~MethodCall() {

}


/**
* Method to handle String object's methods.
* @param obj (JM::String*)
* @param function (std::string)
* @param params (std::vector<JM::Object*>)
* @return JM::Object*
*/
JM::Object* JM::MethodCall::evaluateStringMethod(JM::String* obj, std::string function, std::vector<JM::Object*>& params)
{

    if (function == "concat" || function == "append")
    {

        std::string temp;
        for (int i = 0; i < params.size(); i++)
        {
            if (params[i] != NULL){
                if (params[i]->getCurrentType() == JMString)
                    temp = temp + ((JM::String*)params[i])->getCurrentValue();
                else if (params[i]->getCurrentType() == JMNum)
                    temp = temp + std::to_string( ((JM::Num*)params[i])->getCurrentValue() );
            }
        }

        return obj->concatenate(temp);

    }
    else if (function == "length")
    {
        return new JM::Num( (obj->getCurrentValue()).length() );
    }
    else if (function == "class")
    {
        return new JM::String("JMString");
    }
    else if (function == "writeToFile")
    {
        if (params[0]->getCurrentType() == JMString){
            if (params[0] != NULL && obj != NULL){
	               this->manager.writeToFile(((JM::String*)params[0])->getCurrentValue(), obj->getCurrentValue());
            }
            else {
                std::cout<<"Either params or object was NULL for writeToFile\n";
            }
       }
        else
           std::cout<<"Not a proper file named passed as argument.\n";
    }
    else
    {
        std::cout<<"Not a method of the String class"<<std::endl;
    }

    return NULL;
}

/**
* Method to handle Num object's methods.
* @param obj (JM::Num*)
* @param function (std::string)
* @param params (std::vector<JM::Object*>)
* @return JM::Object*
*/
JM::Object* JM::MethodCall::evaluateNumMethod(JM::Num* obj, std::string function, std::vector<JM::Object*>& params)
{

    if (function == "add" || function == "+")
    {
        double temp = obj->getCurrentValue();
        for (int i = 0; i < params.size(); i++)
        {
            if (params[i]->getCurrentType() == JMNum)
                temp += ((JM::Num*)params[i])->getCurrentValue();
        }
        return new JM::Num(temp);

    }
    else if (function == "sub" || function == "-")
    {
        double temp = obj->getCurrentValue();
        for (int i = 0; i < params.size(); i++)
        {
            if (params[i]->getCurrentType() == JMNum)
                temp -= ((JM::Num*)params[i])->getCurrentValue();
        }
        return new JM::Num(temp);
    }
    else if (function == "mul" || function == "*")
    {
        double temp = obj->getCurrentValue();
        for (int i = 0; i < params.size(); i++)
        {
            if (params[i]->getCurrentType() == JMNum)
                temp *= ((JM::Num*)params[i])->getCurrentValue();
        }
        return new JM::Num(temp);
    }
    else if (function == "div" || function == "/")
    {
        double temp = obj->getCurrentValue();
        for (int i = 0; i < params.size(); i++)
        {
            if (params[i]->getCurrentType() == JMNum)
                temp /= ((JM::Num*)params[i])->getCurrentValue();
        }
        return new JM::Num(temp);
    }
    else if (function == "pow")
    {

    }
    else if (function == "class")
    {
        return new JM::String("JMNum");
    }
    else
    {
        std::cout<<"Not a method of the Num class"<<std::endl;
    }

    return NULL;
}

JM::Object* JM::MethodCall::evaluateArrayMethod(JM::Array* obj, std::string function, std::vector<JM::Object*>& params)
{

    if (function == "at")
    {
        if (params[0]->getCurrentType() == JMNum)
        {
            return obj->at( ((JM::Num*)params[0])->getCurrentValue());
        }
        else
        {
            std::cout<<"not a number type passed to 'at' method.\n";
        }
    }
    else if (function == "append" || function == "push")
    {
        for (int i = 0; i < params.size(); i++)
        {
            if (params[i] != NULL)
                obj->append(params[i]);
        }
    }
    else if (function == "writeToFile")
    {
        if (params[0]->getCurrentType() == JMString)
        {
            if (params[1] != NULL && params[1]->getCurrentType() == JMString)
            {
                this->manager.writeToFile( ((JM::String*)params[0])->getCurrentValue(),
                                            obj->getCurrentValue(),
                                            ((JM::String*)params[1])->getCurrentValue() );
            }
            else
            {
                this->manager.writeToFile( ((JM::String*)params[0])->getCurrentValue(),
                                            obj->getCurrentValue(), " " );
            }
        }
        else
            std::cout<<"Parameter to 'writeToFile' was not a proper string.\n";
    }
    else if (function == "length")
    {
        return new JM::Num((double)obj->getLength());
    }
    else if (function == "class")
    {
        return new JM::String("JMArray");
    }
    else
    {
        std::cout<<"Not a method of the Array class.\n";
    }

    return NULL;

}
