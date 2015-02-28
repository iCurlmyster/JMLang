#ifndef JMNUM_HPP
#define JMNUM_HPP

#include "JMObject.hpp"

namespace JM {

        class Num : public JM::Object {


            double currentValue;

        public:
            Num();
            Num(std::string s);
            Num(double d);
            ~Num();

            double getCurrentValue();
            JM::Num* add(double d);
            JM::Num* sub(double d);
            JM::Num* mul(double d);
            JM::Num* div(double d);

        };


};


#endif
