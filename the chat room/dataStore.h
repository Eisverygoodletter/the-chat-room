#pragma once
#include <all.h>
#include <map>

namespace dS {
	//stands for dataStore
	class storeClass {
	public:
		int encryption;
		storeClass();
	};
	std::ostream& operator<<(std::ostream& os, dS::storeClass const& m);
	extern void startSettings();
	extern std::map<std::string, int> settings;
}