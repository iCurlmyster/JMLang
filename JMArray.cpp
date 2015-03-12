#include "JMArray.hpp"

JM::Array::Array() {
	this->currentType = JMArray;
}
JM::Array::~Array() {}
JM::Array::Array(std::vector<JM::Object*>& objVec)
{
	this->currentType = JMArray;
	this->objVec = objVec;
}
std::vector<JM::Object*> JM::Array::getCurrentValue()
{
	return this->objVec;
}
