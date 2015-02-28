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
            JM::Num* add(JM::Num *n);
            JM::Num* sub(JM::Num *n);
            JM::Num* mul(JM::Num *n);
            JM::Num* div(JM::Num *n);

        };


};


#endif
