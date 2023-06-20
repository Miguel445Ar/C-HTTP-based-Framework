// BackendLibrary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "networking/HTTP_Server.h"
#include <mysql.h>
#include <string>
#include <typeinfo>
#include <variant>
#include "types/Integer.hpp"
#include "types/String.hpp"
#include "types/Float.hpp"
#include "mysql-module/utils.hpp"
#include "mysql-module/types/Entity.hpp"
#include "app/app.hpp"


#define API_CONTROLLER(ENDPOINT_NAME)


using namespace types;

class MyClass: persistanceTypes::Entity {
public:
    Integer integer;
    String text;
    MyClass(Integer integer, String text): integer(integer), text(text), Entity("my_class") {}
};

int main()
{
    MYSQL* conn;
    conn = mysql_init(NULL);
    conn = mysql_real_connect(conn, "localhost", "root", "root", "ma", 3306, nullptr, 0);
    if (conn) std::cout << "Successful connection\n";
    else std::cout << "An error occured while trying to connect\n";
    //std::cout << formatQuery("provider", "%d %s", 1, "proveedor 1");
    MyClass example = MyClass(Integer(10),String("example 1"));
    std::cout << toQueryFormat<MyClass>(example) << "\n";
    return 0;
}
