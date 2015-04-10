#ifndef JMPARSER_HPP
#define JMPARSER_HPP

#include <string>
#include <vector>
#include "JMTypes.h"


namespace JM {
	class Parser
	{

		/**
		* Instance variable to hold the current string being parsed.
		* @type std::string
		*/
		std::string parsedString;

		/**
		* Instance variable to hold the current Type the parsedString is.
		* @type JMType
		*/
		JMType currentType;
	public:
		Parser();
		~Parser();

		/**
		* Method to set parsedString variable with string passed
		* as parameter and then match the type of what the string is and
		* set the currentType variable to the corresponding type.
		*
		* @param line std::string
		* @return JMType
		*/
		JMType evaluateParse(std::string line);

		/**
		* Method to return the current string thats held by this class
		* broken up by what type it is.
		*
		* @return std::vector<std::string>
		*/
		std::vector<std::string> returnParsedString();

		/**
		* Method to split a string into a std::vector by a specfied delimiter.
		*
		* @param line std::string
		* @param del std::string
		* @return std::vector<std::string>
		*/
		static std::vector<std::string> split(std::string line, std::string del);
	};
}

#endif
