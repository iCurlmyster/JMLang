#ifndef JMOBJECT_HPP
#define JMOBJECT_HPP

#include "JMTypes.h"

namespace JM {
class Object {

	JMType currentType;
	unsigned int id;
public:
	Object();
	~Object();
	
	void description();
};
};


#endif
