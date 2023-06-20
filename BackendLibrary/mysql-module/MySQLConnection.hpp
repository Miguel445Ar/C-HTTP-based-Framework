#pragma once
#include <mysql.h>
#include <memory>
#include <string.h>

class MySQLConnection {
	MySQLConnection();
	~MySQLConnection();
public:
	MySQLConnection(MySQLConnection&& other) = delete;
	MySQLConnection(MySQLConnection& other) = delete;
	static const std::unique_ptr<MySQLConnection>& getConnection();
	static void deleteConnection();
	static std::unique_ptr<MySQLConnection> connection;
	void runQuery(const char* query);
private:
	MYSQL* _connection;
};