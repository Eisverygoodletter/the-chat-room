#include "dataStore.h"
#include <map>
std::map<std::string, int> dS::settings = std::map<std::string, int>();

dS::storeClass::storeClass() {
	this->encryption = DEFAULT_ENCRYPTION;
}

std::ostream& operator<<(std::ostream& os, dS::storeClass const& m) {
	return os << "encryption: " + std::to_string(m.encryption) + "\n";
}