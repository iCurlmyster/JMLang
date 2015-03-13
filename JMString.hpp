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
        JM::String* concatenate(JM::String* obj);
        JM::String* concatenate(std::string s);

        std::string toString() const;

    };

};


#endif
