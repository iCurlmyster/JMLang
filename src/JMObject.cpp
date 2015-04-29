#include "JMObject.hpp"

JM::Object::Object() {}
JM::Object::~Object() {}

int JM::Object::getScope() { return this->scope; }

JMType JM::Object::getCurrentType() {return this->currentType; }

std::string JM::Object::toString() const { return ""; }
