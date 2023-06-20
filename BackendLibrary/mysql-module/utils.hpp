#pragma once
#include "../types/BaseType.hpp"
#include "../types/String.hpp"
#include <type_traits>


/*
* Type T have to use only data types defined in this library, otherwise this function will crash
* at runtime
*/
template<class T>
const char* toQueryFormat(T e) {
    if (!std::is_base_of<T, types::BaseType>)
        throw std::runtime_error("Type T is not derived from BaseType")
    unsigned int sThis = sizeof(e);
    unsigned int btSize = sizeof(types::BaseType);
    unsigned int length = sThis / btSize;
    types::BaseType* it = (types::BaseType*)&e;
    ++it;
    --length;
    std::string strIt = "(";
    for (int i = 0; i < length; ++i, ++it) {
        std::cout << it->toString() << "\n";
        if (it->getType() != 2) {
            strIt += it->toString();
        }
        else {
            strIt += "'";
            strIt += it->toString();
            strIt += "'";
        }
        if (i < length - 1)
            strIt += ",";
    }
    strIt += ");";
    return types::String::toCharArray(strIt);
}
