#include "dataStore.h"
#include <fstream>

void dS::startSettings() {
	// for creating an empty file on start up via holding the R key on the keyboard
	storeClass toStoreval = storeClass();
	std::ofstream file;
	file.open(SETTINGS_FILE_NAME, std::ios::out);
	file.write((char*)&toStoreval, sizeof(dS::storeClass));
	file.close();
}