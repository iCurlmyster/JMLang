#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>
#include "JMGlobalFunctions.h"
#include "JMParser.hpp"
#include "JMObject.hpp"
#include "JMString.hpp"
using namespace std;

map<string, JM::Object *> variables;


int main(int argc, const char * argv[])
{

	if (regex_match(argv[1],regex("[\\w+\\s*]+\\.jm")))
	{
		int lineNumber = 0;
		JM::Parser parserObject; 
		string line;
		ifstream f(argv[1]);
		while (!f.eof())
		{
			++lineNumber;
			smatch matches;
			getline(f,line);
			JMType parseType = parserObject.evaluateParse(line);
			if (parseType == JMFunc)
			{
				vector<string> lineString = parserObject.returnParsedString();
				if (lineString[0] == "print")
				{
					JMType printType = parserObject.evaluateParse(lineString[1]);
					vector<string> printVec;

					if (printType == JMString) printVec = parserObject.returnParsedString();
					if (printType == JMVar)
					{

						vector<string> varvec = parserObject.returnParsedString();

						JM::String* strTemp = (JM::String*)(variables[(parserObject.returnParsedString())[0]]);

					 	printVec.push_back(strTemp->getCurrentValue());
					}
					if (printType == JMError) { cout<<"Error on line: "<<lineNumber<<endl; printVec.push_back(""); }
					else printVec.push_back(lineString[1]);
				 	print(printVec[0]);
				}
				if (lineString[0] == "println")
				{
					JMType printType = parserObject.evaluateParse(lineString[1]);
					vector<std::string> printVec;

					if (printType == JMString) printVec = parserObject.returnParsedString();
					else if (printType == JMError) cout<<"Error on line: "<<lineNumber<<endl;
					else if (printType == JMVar)
					{

						vector<string> varvec = parserObject.returnParsedString();

						JM::String* strTemp = (JM::String*)(variables[(parserObject.returnParsedString())[0]]);

						printVec.push_back(strTemp->getCurrentValue());
					}
					else printVec.push_back(lineString[1]);
				 	println(printVec[0]);
				}

			}
			if (parseType == JMAssign)
			{
				vector<string> lineString = parserObject.returnParsedString();
				if( lineString.size() > 0){

					JMType assignType = parserObject.evaluateParse(lineString[2]);

					if (assignType == JMString)
					{
						vector<string> printVec = parserObject.returnParsedString();
						JM::String *strObj = new JM::String(printVec[0]);
						variables[lineString[1]] = strObj;
					}
					else {
						cout<<"Not a string\n";
					}
				}
				else
				{
					cout<<"string was not formatted correctly for assignment.\n";
				}
			}
			// regex_match(line,matches,regex("print:\\s\"([\\w+\\s*]*)\""));
			// cout<< matches[1]<<endl;
		}
		f.close();
	}
	else
	{
		cout<<"Not a proper jm file.\n";
	}
	return 0;
}
