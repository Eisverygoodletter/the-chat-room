#pragma once
#include <all.h>

namespace dS {
	//stands for dataStore
	class storeClass {
	public:
		std::string encryption;
		storeClass(); // constructor
	};
	std::ostream& operator<<(std::ostream& os, dS::storeClass const& m);
	extern void startSettings();
}