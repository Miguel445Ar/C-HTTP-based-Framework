#include "Repository.hpp"

template<class T>
Repository<T>::Repository()
{
	this->_connection = MySQLConnection::getConnection().get();
}

template<class T>
Repository<T>::~Repository()
{
	this->_connection = nullptr;
}

template<class T>
bool Repository<T>::insertToTable(T item)
{
	// TODO: Check if item is derived of Entity with std::is_base_of
	
	std::string query = "INSERT INTO TABLE " + item.getTableName() + " VALUES " + toQueryFormat<T>(item);
	this->_connection->runQuery(types::String::toCharArray(query));
}

