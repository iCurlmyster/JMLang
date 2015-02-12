#ifndef JMNUM_HPP
#define JMNUM_HPP

#include "JMObject.hpp"

namespace JM {

        class Num : JM::Object {


            double currentValue;

        public:
            Num();
            Num(std::string s);
            ~Num();

            double getCurrentValue();


        };


};


#endif
