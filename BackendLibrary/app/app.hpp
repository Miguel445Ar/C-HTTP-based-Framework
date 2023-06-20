#pragma once
#include "../routes/RoutesManager.hpp"
#include <functional>
class App {
	RoutesManager* routes;
public:
	App();
	void post(const char* route, std::function<void(void)> behavior);
};