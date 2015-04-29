#include "JMParser.hpp"
#include <regex>
#include <iostream>


JM::Parser::Parser()
{

}

JM::Parser::~Parser()
{

}

/**
* Method to set parsedString variable with string passed
* as parameter and then match the type of what the string is and
* set the currentType variable to the corresponding type.
*
* @param line std::string
* @return JMType
*/
JMType JM::Parser::evaluateParse(std::string line)
{
	this->parsedString = line;
	if (std::regex_match(line,std::regex("\\s*//.*")))
	{
		return JMNull;
	}
	else if (std::regex_match(line, std::regex("\\s*\\{.+\\}\\s*")))
	{
		this->currentType = JMDefFunc;
		return this->currentType;
	}
	else if (std::regex_match(line,std::regex(".+\\s+=\\s+.+")))
	{
		this->currentType = JMAssign;
		return this->currentType;
	}
	else if (std::regex_match(line, std::regex("\\s*\\[.*\\]\\s*")))
	{
		this->currentType = JMArray;
		return this->currentType;
	}
	else if (std::regex_match(line, std::regex("\\s*-{0,1}[0-9]+\\.{0,1}[0-9]*\\s*")))
	{
		//std::cout<<"Number\n";
		this->currentType = JMNum;
		return this->currentType;
	}
	else if (std::regex_match(line, std::regex("\\s*\"[^\"]*\"\\s*")))
	{
		//std::cout<<"String\n";
		this->currentType = JMString;
		return this->currentType;
	}
	else if (std::regex_match(line, std::regex("^\"{0,1}.+\"{0,1}\\.[\\w|\\-|\\+|\\*|/]+: .+$")))
	{
		//std::cout<<"Calling method in parser\n";
		this->currentType = JMMethod;
		return this->currentType;
	}
	else if (std::regex_match(line,std::regex("[\\w|\\-|\\+|\\*|/]+: .*")))
	{
		//std::cout<<"function\n";
		this->currentType = JMFunc;
		return this->currentType;
	}
	else if (std::regex_match(line, std::regex(".*\\w+.*")))
	{
		//std::cout<<"JMVar regex\n";
		this->currentType = JMVar;
		return this->currentType;
	}

	//std::cout<<"null\n";
	return JMNull;
}


/**
* Method to return the current string thats held by this class
* broken up by what type it is.
*
* @return std::vector<std::string>
*/
std::vector<std::string> JM::Parser::returnParsedString()
{
	std::smatch sm;
	std::vector<std::string> splitVec;
	if (this->currentType == JMAssign)
	{
		std::regex_match(this->parsedString,sm,std::regex("([a-z]\\w+)\\s+=\\s+(.+)"));
		splitVec.push_back(sm[1]);
		splitVec.push_back(sm[2]);
	}

	if (this->currentType == JMMethod)
	{
		std::regex_match(this->parsedString, sm, std::regex("^(\"{0,1}.+\"{0,1})\\.([\\w|\\+|\\-|\\*|/]+: .+)$"));
		splitVec.push_back(sm[1]);
		splitVec.push_back(sm[2]);
	}

	if (this->currentType == JMFunc)
	{
		splitVec = JM::Parser::split(this->parsedString, ": ");
	}

	if (this->currentType == JMString)
	{
		std::regex_match(this->parsedString, sm, std::regex("\\s*\"(.*)\"\\s*"));
		splitVec.push_back(sm[1]);
	}

	if (this->currentType == JMNum)
	{
		std::regex_match(this->parsedString, sm, std::regex("\\s*(-{0,1}[0-9\\.]*)\\s*"));
		splitVec.push_back(sm[1]);
	}

	if (this->currentType == JMVar)
	{
		std::regex_match(this->parsedString,sm,std::regex("\\s*(\\w+)\\s*"));
		splitVec.push_back(sm[1]);
	}
	if (this->currentType == JMArray)
	{
		std::regex_match(this->parsedString, sm, std::regex("\\s*\\[(.*)\\]\\s*"));
		splitVec = JM::Parser::split(sm[1],", ");
	}
	if (this->currentType == JMDefFunc)
	{
		std::regex_match(this->parsedString, sm, std::regex("\\s*\\{\\s*\\[(.*)\\]\\s:\\s(.*)\\s*\\}\\s*"));
		std::string test_params = sm[1];
		std::string test_ops = sm[2];
		// if (!std::regex_match(test_ops,std::regex("^\\s*$")))
		// {
		// 	return splitVec;
		// }
		if (!std::regex_match(test_params,std::regex("^\\s*$")))
		{
			auto params = JM::Parser::split(sm[1],", ");
			auto opera = JM::Parser::split(sm[2],"; ");

			for (auto& p: params)
			{
				splitVec.push_back(p);
			}
			splitVec.push_back(":");
			for (auto& o: opera)
			{
				splitVec.push_back(o);
			}
			return splitVec;
		}
		else
		{
			auto opera = JM::Parser::split(sm[2],"; ");
			splitVec.push_back(":");
			for (auto& o: opera)
			{
				splitVec.push_back(o);
			}
			return splitVec;
		}
	}

	return splitVec;
}


/**
* Method to split a string into a std::vector by a specfied delimiter.
*
* @param line std::string
* @param del std::string
* @return std::vector<std::string>
*/
std::vector<std::string> JM::Parser::split(std::string line, std::string del)
{
	size_t found = line.find(del);
	std::vector<std::string> temp;
	size_t previous = 0;
	bool notDone = true;
	while (notDone)
	{
		if(found != std::string::npos)
		{
			temp.push_back(line.substr(previous, found - previous));
			previous = found + del.length();
			found = line.find(del,previous);
		}
		else
		{
			notDone = false;
			std::string sub = line.substr(previous);

			temp.push_back(sub);
		}
	}
	return temp;
}
