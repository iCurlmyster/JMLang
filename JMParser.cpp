#include "JMParser.hpp"
#include <regex>
#include <iostream>

JM::Parser::Parser()
{

}

JM::Parser::~Parser()
{

}

JMType JM::Parser::evaluateParse(std::string line)
{
	this->parsedString = line;
	if (std::regex_match(line,std::regex(".+=.+")))
	{

		// if (this->currentType == JMFunc) {
		// 	std::cout<<"\ncannot use '=' operator in functions call\n";
		// 	return JMError;
		// }
		//std::cout<<"assign\n";
		this->currentType = JMAssign;
		return this->currentType;
	}
	if (std::regex_match(line,std::regex("\\w+: .*")))
	{
		//std::cout<<"function\n";
		this->currentType = JMFunc;
		return this->currentType;
	}
	if (std::regex_match(line, std::regex(".*\".*\".*")))
	{
		//std::cout<<"String\n";
		this->currentType = JMString;
		return this->currentType;
	}
	if (std::regex_match(line, std::regex(".*\\w+.*")))
	{
		//std::cout<<"JMVar regex\n";
		this->currentType = JMVar;
		return this->currentType;
	}

	//std::cout<<"null\n";
	return JMNull;
}

std::vector<std::string> JM::Parser::returnParsedString()
{
	std::smatch sm;
	std::vector<std::string> splitVec;
	if (this->currentType == JMAssign)
	{
		std::regex_match(this->parsedString,sm,std::regex("(\\w+)\\s*=\\s*(.+)"));
		for (int i = 0; i < sm.size(); i++)
		{
			splitVec.push_back(sm[i]);
		}

	}

	if (this->currentType == JMFunc)
	{
		splitVec = JM::Parser::split(this->parsedString, ": ");
	}

	if (this->currentType == JMString)
	{
		std::regex_match(this->parsedString, sm, std::regex("\"(.*)\""));
		splitVec.push_back(sm[1]);
	}

	if (this->currentType == JMVar)
	{

		std::regex_match(this->parsedString,sm,std::regex("\\s*(\\w+)\\s*"));
		splitVec.push_back(sm[1]);
	}

	return splitVec;
}

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
			temp.push_back(line.substr(previous,found));
			previous = found + del.size();
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
