#ifndef JMNUM_HPP
#define JMNUM_HPP

#include "JMObject.hpp"

namespace JM {

        class Num : public JM::Object {


            double currentValue;

        public:
            Num();
            Num(std::string s);
            ~Num();

            double getCurrentValue();
            double add(JM::Num *n);
            double sub(JM::Num *n);
            double mul(JM::Num *n);
            double div(JM::Num *n);
            double mod(JM::Num *n);

        };


};


#endif
