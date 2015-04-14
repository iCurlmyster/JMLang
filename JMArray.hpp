#ifndef JMARRAY_HPP
#define JMARRAY_HPP

#include "JMFiles.hpp"
#include <vector>
#include <string>


namespace JM {

	class Array : public JM::Object {

	std::vector<JM::Object*> objVec;

	public:
		Array();
		Array(std::vector<JM::Object*>& objVec);
		~Array();

		std::vector<JM::Object*> getCurrentValue();
		void append(JM::Object* obj);
		JM::Object* at(int n);
		int getLength();

		template<typename F>
		void mutationMap(F func)
		{
			// implement
		}


		std::string toString() const;
	};

};


#endif
