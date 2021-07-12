#pragma once
#include <all.h>
#include <map>

namespace dS {
	//stands for dataStore
	extern std::string username;
	extern void startSettings();
	extern std::map<std::string, int> settings;
}