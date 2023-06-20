#pragma once
#include <vector>
#include <unordered_map>
#include <string>

enum JSON_TYPE {
	JSON_INT,
	JSON_FLOAT,
	JSON_STRING,
	JSON_NULL,
	JSON_LIST,
	JSON_OBJECT,
	JSON_BOOL
};

struct JSONData {
	JSON_TYPE type;
	union jsonval {
		void* null;
		int integer;
		float decimal;
		char* text;
		bool boolean;
		std::vector<JSONData*>* list;
		std::unordered_map<std::string, void*> object;
	};
	jsonval value;
};