#ifndef JMDEFFUNC_HPP
#define JMDEFFUNC_HPP

#include "JMObject.hpp"
#include <vector>
#include <string>

namespace JM {

    class DefFunc : public JM::Object {

        std::vector<std::string> parameters;
        std::vector<std::string> operations;
    public:
        DefFunc();
        ~DefFunc();
        void setParameters(std::vector<std::string> par);
        void setOperations(std::vector<std::string> op);
        std::vector<std::string> getParameters();
        std::vector<std::string> getOperations();
        std::string toString() const;

    };

};

#endif
