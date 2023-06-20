#pragma once
#include "BaseType.hpp"

namespace types {
    class String : public BaseType {
    public:
        String() : BaseType() {
            this->value.text = (char*)"";
            this->typeName = CHAR_POINTER;
        }
        String(const char* text) : BaseType() {
            this->value.text = (char*)text;
            this->typeName = CHAR_POINTER;
        }
        const char* toString() const override {
            return (const char*)this->value.text;
        }
        friend ostream& operator<<(ostream& os, String i) {
            os << i.value.text;
            return os;
        }
        static const char* toCharArray(const std::string& str) {
            char* copy = new char[str.length() + 1];
            for (size_t i = 0; i < str.size(); ++i)
                copy[i] = str[i];
            copy[str.length()] = '\0';
            return (const char*)copy;
        }
    };
}