#pragma once
#include "JsonData.hpp"

namespace JSON_BUILDER {
	JSONData* createJsonInt(const int number);
	JSONData* createJsonFloat(const float decimal);
	JSONData* createJsonString(std::string text);
	JSONData* createJsonBool(const bool boolean);
}