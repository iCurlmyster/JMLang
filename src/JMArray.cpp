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
void JM::Array::append(JM::Object* obj)
{
	this->objVec.push_back(obj);
}
JM::Object* JM::Array::at(int n)
{
	if (n < this->objVec.size())
		return this->objVec[n];
	return NULL;
}
int JM::Array::getLength()
{
	return this->objVec.size();
}


std::string JM::Array::toString() const
{
	std::string str = "";
	for (auto& temp: objVec)
	{
		str += temp->toString() + " ";
	}
	return str;
}
