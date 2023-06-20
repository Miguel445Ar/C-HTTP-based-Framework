#pragma once
#include <iostream>
#include <cmath>
#include <string>

using std::ostream;
using std::pow;

namespace types {
    class BaseType abstract {
    protected:
        union type {
            int number;
            float decimal;
            char* text = (char*)"";
            bool boolean;
        };
        enum type_name {
            INT,
            FLOAT,
            CHAR_POINTER,
            DOUBLE,
            SHORT,
            BOOLEAN
        };
        type value;
        type_name typeName;
    public:
        BaseType() {}
        int getType() { return this->typeName; }
        virtual const char* toString() const abstract;
    };
}