#ifndef JMPARSER_HPP
#define JMPARSER_HPP

#include <string>
#include <iostream>
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
		template<typename T>
		T returnParsedString()
		{
			if (currentType == JMNum)
				return (double)parsedString;
			if (currentType == JMBool)
				return (bool)parsedString;

			return parsedString;
		};
	};
}

#endif
