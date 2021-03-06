#ifndef JMOBJECT_HPP
#define JMOBJECT_HPP

#include "JMTypes.h"
#include <iostream>
#include <string>

namespace JM {
class Object {

protected:
	JMType currentType;
	unsigned int id;
	int scope = 0;
public:
	Object();
	~Object();

	int getScope();

	JMType getCurrentType();

	virtual std::string toString() const;

};
};




#endif
