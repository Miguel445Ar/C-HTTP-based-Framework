#pragma once
#include <mysql.h>
#include <iostream>
#include "MySQLConnection.hpp"
#include "utils.hpp"
#include <functional>
#include <string>
#include <type_traits>
#include <memory>
#include "../types/String.hpp"

template<class T>
class Repository {
public:
	Repository();
	~Repository();
	bool insertToTable(T item);
	bool deleteFrom(T item);
	void updateFrom(T item);
	virtual bool deleteByRange(std::function<bool(T)> criteria);
	virtual bool updateByRange(std::function<bool(T)> criteria);
	void getAll();
	virtual void getAllByRange(std::function<bool(T)> criteria);
private:
	const char* _tableName;
	MySQLConnection* _connection;
};