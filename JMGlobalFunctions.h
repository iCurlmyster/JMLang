#ifndef JMFUNCTIONS_HPP
#define JMFUNCTIONS_HPP

#include <string>
#include <iostream>
#include <vector>
#include "JMFiles.hpp"

void print(std::string line)
{
    std::cout<<line;
}
void println(std::string line)
{
    std::cout<<line<<std::endl;
}
void print(std::vector<JM::Object*> objVec)
{
	if (objVec[0]->getCurrentType() == JMNum)	
		std::cout<<((JM::Num*)objVec[0])->getCurrentValue();
	if (objVec[0]->getCurrentType() == JMString)	
		std::cout<<((JM::String*)objVec[0])->getCurrentValue();

	for (int i = 1; i < objVec.size(); i++)
	{
		if (objVec[i]->getCurrentType() == JMNum)	
			std::cout<< " "<<((JM::Num*)objVec[i])->getCurrentValue();
		if (objVec[i]->getCurrentType() == JMString)
			std::cout<< " "<<((JM::String*)objVec[i])->getCurrentValue();
	}
}
void println(std::vector<JM::Object*> objVec)
{
	if (objVec[0]->getCurrentType() == JMNum)	
		std::cout<<((JM::Num*)objVec[0])->getCurrentValue();
	if (objVec[0]->getCurrentType() == JMString)	
		std::cout<<((JM::String*)objVec[0])->getCurrentValue();

	for (int i = 1; i < objVec.size(); i++)
	{
		if (objVec[i]->getCurrentType() == JMNum)	
			std::cout<< " "<<((JM::Num*)objVec[i])->getCurrentValue();
		if (objVec[i]->getCurrentType() == JMString)
			std::cout<< " "<<((JM::String*)objVec[i])->getCurrentValue();
	}

	std::cout<<"\n";
}

#endif
