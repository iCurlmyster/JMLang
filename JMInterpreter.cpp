#include "JMInterpreter.hpp"
#include "JMGlobalFunctions.h"
#include "JMArray.hpp"

JM::Interpreter::Interpreter()
{

}

JM::Interpreter::~Interpreter()
{

}

/**
* This method sees what type the initial parse is and sends it to it's respective
* method to be dealt with in it's own needs.
* Unless the initial parse is one of these types it skips the line.
* @param &parser (JM::Parser)
* @param type (JMType)
*/

void JM::Interpreter::interpret(JM::Parser& parser, JMType type)
{

    if (type == JMFunc)
    {
        this->func(parser);
    }
    else if (type == JMAssign)
    {
        this->assign(parser);
    }
    else if (type == JMMethod)
    {
        this->method(parser);
    }

}


/**
* This Method handles the assignment operations that need to be done.
* It sends the assignment to the parser to figure out what the value is
* and then assigns that value to the type object and stores it in a HashMap
* with the variable name as it's key to be accessed later.
* @param &parser (JM::Parser)
*/
void JM::Interpreter::assign(JM::Parser& parser)
{
    vector<string> lineString = parser.returnParsedString();
    if( lineString.size() > 0){

        JMType assignType = parser.evaluateParse(lineString[1]);

        if (assignType == JMString)
        {
            vector<string> printVec = parser.returnParsedString();
            JM::String *strObj = new JM::String(printVec[0]);
            variables[lineString[0]] = strObj;
        }
        else if (assignType == JMNum)
        {
            vector<string> printVec = parser.returnParsedString();
            JM::Num *numObj = new JM::Num(printVec[0]);
            variables[lineString[0]] = numObj;
        }
        else if (assignType == JMMethod)
        {
            auto var = this->method(parser);
            if (var != NULL)
                variables[lineString[0]] = var;
            else
                std::cout<<"Error with method call for assignment to "<<lineString[0]<<std::endl;
        }
	else if (assignType == JMArray)
	{
		vector<string> printVec = parser.returnParsedString();
		vector<JM::Object*> objVec;
		for (int i = 0; i < printVec.size(); i++)
		{
			JMType i_type = parser.evaluateParse(printVec[i]);
			objVec.push_back( this->handleInterpret(parser, i_type) );
		}
		variables[lineString[0]] = new JM::Array(objVec);
	}
        else {
            cout<<"Not assignable.\n";
        }
    }
    else
    {
        cout<<"Not formatted correctly for assignment.\n";
    }
}


/**
* This method handles a function call. It sets the parsed string
* into a vector variable and decides which function it is, then takes action
* on the passed parameters and responds to them accordingly.
* @param &parser (JM::Parser)
*/
void JM::Interpreter::func(JM::Parser& parser)
{
    vector<string> lineString = parser.returnParsedString();
    if (lineString.size() == 0) {std::cout<< "Function not properly set.\n"; return; }
    if (lineString[0] == "print")
    {
        JMType printType = parser.evaluateParse(lineString[1]);
        JM::Object* temp = handleInterpret(parser,printType);

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
	    else if (temp->getCurrentType() == JMArray)
	    {
		auto tempVal = ((JM::Array*)temp)->getCurrentValue();
		print(tempVal);
            }
        }
        else
        {
            std::cout<<"Object was NULL\n";
        }
    }
    else if (lineString[0] == "println")
    {
        JMType printType = parser.evaluateParse(lineString[1]);
        JM::Object* temp = handleInterpret(parser,printType);

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
	    else if (temp->getCurrentType() == JMArray)
	    {
		auto tempVal = ((JM::Array*)temp)->getCurrentValue();
		println(tempVal);
            }

        }
        else
        {
            std::cout<<"Object was NULL\n";
        }

    }
}

/**
* This method handles method calls. It figures out the type of the calling object
* and acts accordingly, evaluating all of the method's parameters and then passes the information
* to the JMMethodCall class to handle what type of object method it is and the parameters that
* are passed to it. Once JMMethodCall handles the method it returns an object and then this
* method returns that returned object. Cannot handle method within method calling yet.
* @param &parser (JM::Parser)
* @return JM::Object*
*/
JM::Object* JM::Interpreter::method(JM::Parser& parser)
{

    vector<string> lineString = parser.returnParsedString();
    if (lineString.size() == 0) {std::cout<<"Method was not called properly.\n"; return NULL; }
    JMType callerType = parser.evaluateParse(lineString[0]);
    if (callerType == JMVar)
    {
        auto var = this->handleInterpret(parser,JMVar);
        JMType varType = var->getCurrentType();

        if (varType == JMString)
        {
            JM::String * tempVar = (JM::String*)var;
            JMType funcType = parser.evaluateParse(lineString[1]);
            if (funcType == JMFunc) {

                string theFunction;
                vector<string> funcString = parser.returnParsedString();
                vector<JM::Object*> parameters;

                theFunction = funcString[0];

                for (int i = 1; i < funcString.size(); i++)
                {
                    JMType paramType = parser.evaluateParse(funcString[i]);
                    auto paramObject = this->handleInterpret(parser, paramType);
                    if (paramObject != NULL)
                        parameters.push_back(paramObject);
                }

                return methodCalls.evaluateStringMethod(tempVar, theFunction, parameters);
            }
            else
            {
                std::cout<<"Method not properly called.\n";
            }
        }
        else if (varType == JMNum)
        {
            JM::Num * tempVar = (JM::Num*)var;
            JMType funcType = parser.evaluateParse(lineString[1]);
            if (funcType == JMFunc) {

                string theFunction;
                vector<string> funcString = parser.returnParsedString();
                vector<JM::Object*> parameters;

                theFunction = funcString[0];

                for (int i = 1; i < funcString.size(); i++)
                {
                    JMType paramType = parser.evaluateParse(funcString[i]);
                    auto paramObject = this->handleInterpret(parser, paramType);
                    if (paramObject != NULL)
                        parameters.push_back(paramObject);
                }

                return methodCalls.evaluateNumMethod(tempVar, theFunction, parameters);
            }
            else
            {
                std::cout<<"Method not properly called.\n";
            }
        }
    }

    if (callerType == JMString)
    {
        JM::String * tempVar = (JM::String*)this->handleInterpret(parser, callerType);
        JMType funcType = parser.evaluateParse(lineString[1]);
        if (funcType == JMFunc) {

            string theFunction;
            vector<string> funcString = parser.returnParsedString();
            vector<JM::Object*> parameters;

            theFunction = funcString[0];

            for (int i = 1; i < funcString.size(); i++)
            {
                JMType paramType = parser.evaluateParse(funcString[i]);
                auto paramObject = this->handleInterpret(parser, paramType);
                if (paramObject != NULL)
                    parameters.push_back(paramObject);
            }

            return methodCalls.evaluateStringMethod(tempVar, theFunction, parameters);
        }
        else
        {
            std::cout<<"Method not properly called.\n";
        }
    }
    else if (callerType == JMNum)
    {
        JM::Num * tempVar = (JM::Num*)this->handleInterpret(parser, callerType);
        JMType funcType = parser.evaluateParse(lineString[1]);
        if (funcType == JMFunc) {

            string theFunction;
            vector<string> funcString = parser.returnParsedString();
            vector<JM::Object*> parameters;

            theFunction = funcString[0];

            for (int i = 1; i < funcString.size(); i++)
            {
                JMType paramType = parser.evaluateParse(funcString[i]);
                auto paramObject = this->handleInterpret(parser, paramType);
                if (paramObject != NULL)
                    parameters.push_back(paramObject);
            }

            return methodCalls.evaluateNumMethod(tempVar, theFunction, parameters);
        }
        else
        {
            std::cout<<"Method not properly called.\n";
        }
    }

    return NULL;

}

/**
* This method handles the interpreting of what the object type is and creates
* an object for that type and returns it.
* @param &parser (JM::Parser)
* @param type (JMType)
* @return JM::Object*
*/
JM::Object* JM::Interpreter::handleInterpret(JM::Parser& parser,JMType type)
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
