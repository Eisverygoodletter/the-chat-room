#include "openPage.h"
#include <all.h>
#include <fstream>

void oP::loadSettings() {
	std::ifstream settingsFile;
	settingsFile.open(SETTINGS_FILE_NAME);
	dS::storeClass toStore;
	settingsFile.read((char*)&toStore, sizeof(dS::storeClass));
	settingsFile.close();
}