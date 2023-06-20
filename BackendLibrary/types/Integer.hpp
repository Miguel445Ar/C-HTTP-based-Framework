#pragma once
#include "BaseType.hpp"

namespace types {
    class Integer : public BaseType {
    public:
        Integer() : BaseType() {
            this->value.number = -1;
            this->typeName = INT;
        }
        Integer(int integer) : BaseType() {
            this->value.number = integer;
            this->typeName = INT;
        }
        void operator=(const Integer i) { this->value.number = i.value.number; }
        const Integer operator+(const Integer i) const { return Integer(this->value.number + i.value.number); }
        const Integer operator-(const Integer i) const { return Integer(this->value.number + i.value.number); }
        const Integer operator*(const Integer i) const { return Integer(this->value.number + i.value.number); }
        const Integer operator/(const Integer i) const { return Integer(this->value.number / i.value.number); }
        const int getValue() const { return this->value.number; }
        const char* toString() const override {
            std::string str = std::to_string(this->value.number);
            size_t len = str.length();
            char* copy = new char[len + 1];
            copy[len] = '\0';
            for (unsigned int i = 0; i < len; ++i)
                copy[i] = str[i];
            return copy;
        }
        friend ostream& operator<<(ostream& os, Integer i) {
            os << i.value.number;
            return os;
        }
    };
}
