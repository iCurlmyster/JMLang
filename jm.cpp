#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "JMInterpreter.hpp"
using namespace std;


int main(int argc, const char * argv[])
{

	if (regex_match(argv[1],regex(".+\\.jm")))
	{
		int lineNumber = 0;
		JM::Parser parserObject;
		JM::Interpreter interpObj;
		string line;
		bool isAnError = false;
		ifstream f(argv[1]);
		while (!f.eof())
		{
			isAnError = false;
			++lineNumber;
			smatch matches;
			getline(f,line);
			JMType parseType = parserObject.evaluateParse(line);
			if (parseType != JMNull)
				interpObj.interpret(parserObject,parseType);
			if (isAnError)
				cout<<"ERROR on line: "<<lineNumber<<endl;

		}
		f.close();
	}
	else
	{
		cout<<"Not a proper jm file.\n";
	}
	return 0;
}
