#ifndef JMPARSER_HPP
#define JMPARSER_HPP

#include <string>
#include <vector>
#include "JMTypes.h"


namespace JM {
	class Parser
	{

		std::string parsedString;
		JMType currentType;
	public:
		Parser();
		~Parser();
		JMType evaluateParse(std::string line);
		std::vector<std::string> returnParsedString();
		static std::vector<std::string> split(std::string line, std::string del);
	};
}

#endif
