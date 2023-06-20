#pragma once
#include "../../types/String.hpp";
#include "../../types/Integer.hpp";

namespace persistanceTypes {
    class Entity {
    protected:
        types::String tableName;
        types::Integer id;
    public:
        Entity(const char* tableName) : tableName(tableName) {
            id = 1;
        }
        const char* getTableName() {
            return tableName.toString();
        }
    };
}