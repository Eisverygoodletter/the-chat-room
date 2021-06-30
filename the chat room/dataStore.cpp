#include "dataStore.h"
dS::storeClass::storeClass() {
	this->encryption = DEFAULT_ENCRYPTION;
}

std::ostream& operator<<(std::ostream& os, dS::storeClass const& m) {
	return os << "encryption: " + m.encryption + "\n";
}