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
	if (std::regex_match(line,std::regex("\\s*//.*")))
	{
		return JMNull;
	}
	else if (std::regex_match(line,std::regex(".+=.+")))
	{
		this->currentType = JMAssign;
		return this->currentType;
	}
	else if (std::regex_match(line, std::regex("-{0,1}[0-9]+\\.{0,1}[0-9]*")))
	{
		//std::cout<<"Number\n";
		this->currentType = JMNum;
		return this->currentType;
	}
	else if (std::regex_match(line, std::regex("^\"{0,1}.+\"{0,1}\\..+$")))
	{
		this->currentType = JMMethod;
		return this->currentType;
	}
	else if (std::regex_match(line,std::regex("[\\w|\\-|\\+|\\*|/]+: .*")))
	{
		//std::cout<<"function\n";
		this->currentType = JMFunc;
		return this->currentType;
	}
	else if (std::regex_match(line, std::regex("\\s*\"[^\"|.]*\"\\s*")))
	{
		//std::cout<<"String\n";
		this->currentType = JMString;
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

std::vector<std::string> JM::Parser::returnParsedString()
{
	std::smatch sm;
	std::vector<std::string> splitVec;
	if (this->currentType == JMAssign)
	{
		std::regex_match(this->parsedString,sm,std::regex("([a-z]\\w+)\\s*=\\s*(.+)"));
		splitVec.push_back(sm[1]);
		splitVec.push_back(sm[2]);
	}

	if (this->currentType == JMMethod)
	{
		std::regex_match(this->parsedString, sm, std::regex("(\"{0,1}.+\"{0,1})\\.(.+)"));
		splitVec.push_back(sm[1]);
		splitVec.push_back(sm[2]);
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

	if (this->currentType == JMNum)
	{
		std::regex_match(this->parsedString, sm, std::regex("(-{0,1}[0-9\\.]*)"));
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
