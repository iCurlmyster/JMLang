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
            Num* add(JM::Num *n);
            Num* sub(JM::Num *n);
            Num* mul(JM::Num *n);
            Num* div(JM::Num *n);
            Num* mod(JM::Num *n);

        };


};


#endif
