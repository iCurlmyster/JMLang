#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "JMInterpreter.hpp"
using namespace std;


int main(int argc, const char * argv[])
{

	if (regex_match(argv[1],regex("[\\w+\\s*]+\\.jm")))
	{
		int lineNumber = 0;
		JM::Parser parserObject;
		JM::Interpreter interpObj;
		string line;
		ifstream f(argv[1]);
		while (!f.eof())
		{
			++lineNumber;
			smatch matches;
			getline(f,line);
			JMType parseType = parserObject.evaluateParse(line);
			interpObj.interpret(parserObject,parseType);
		}
		f.close();
	}
	else
	{
		cout<<"Not a proper jm file.\n";
	}
	return 0;
}