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
	Object() {}
	~Object() {}

	int getScope() { return this->scope; }

	void description() {

		std::string t;
		switch(this->currentType) {

			case JMNull:
				t = "JMNull";
				break;
			case JMError:
				t = "JMError";
				break;
			case JMString:
				t = "JMString";
				break;
			case JMNum:
				t = "JMNum";
				break;
			case JMBool:
				t = "JMBool";
				break;
			case JMFunc:
				t = "JMFunc";
				break;
			case JMAssign:
				t = "JMAssign";
				break;
			case JMVar:
				break;
			default:
				break;
		}

		std::cout<<"Object: "<<t<<std::endl;
		}
};
};


#endif
