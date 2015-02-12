#ifndef JMSTRING_HPP
#define JMSTRING_HPP

#include <string>
#include "JMObject.hpp"

namespace JM {

    class String: public JM::Object
    {

        std::string currentValue;

    public:
        String();
        String(std::string s);
        ~String();
        void setCurrentValue(std::string s);
        std::string getCurrentValue();
        std::string concatenate(JM::String* obj);

    };

};


#endif
