#pragma once
#include "BaseType.hpp"

#include <string.h>
using std::to_string;


namespace types {
    class Float : public BaseType {
    public:
        Float(float decimal) : BaseType() {
            this->value.decimal = decimal;
            this->typeName = FLOAT;
        }
        Float(double decimal) : BaseType() {
            this->value.decimal = (float)decimal;
            this->typeName = FLOAT;
        }
        const char* toString() const override {
            std::string str = to_string(this->value.decimal);
            size_t len = str.length();
            char* copy = new char[len + 1];
            copy[len] = '\0';
            for (unsigned int i = 0; i < len; ++i)
                copy[i] = str[i];
            return copy;
        }
        friend ostream& operator<<(ostream& os, Float i) {
            os << i.value.decimal;
            return os;
        }
    };
}