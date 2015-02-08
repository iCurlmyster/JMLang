#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main(int argc, const char * argv[])
{

	if (regex_match(argv[1],regex("[\\w+\\s*]+\\.jm")))
	{
		string line;
		ifstream f(argv[1]);
		while (!f.eof())
		{
			smatch matches;
			getline(f,line);
			regex_match(line,matches,regex("print:\\s\"([\\w+\\s*]*)\""));
			cout<< matches[1]<<endl;	
		}
		f.close();
	}
	else
	{
		cout<<"Not a jm file.\n";
	}
	return 0;
}
