#include "MySQLConnection.hpp"

MySQLConnection::MySQLConnection()
{
    this->_connection = mysql_init(NULL);
    this->_connection = mysql_real_connect(_connection, "localhost", "root", "root", "ma", 3306, nullptr, 0);
}

MySQLConnection::~MySQLConnection()
{
    mysql_close(this->_connection);
}

const std::unique_ptr<MySQLConnection>& MySQLConnection::getConnection() {
    if (connection != nullptr) {
        connection = std::make_unique<MySQLConnection>();
        return connection;
    }
    return connection;
}

void MySQLConnection::deleteConnection()
{
    connection.reset(nullptr);
}

void MySQLConnection::runQuery(const char* query) {
    int result = mysql_query(this->_connection, query);
    if (result < 0) throw "Unknown error has ocured while trying to execute the query\n";
}
