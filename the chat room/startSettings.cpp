#include "dataStore.h"
#include <fstream>

void dS::startSettings() {
	// for creating an empty file on start up via holding the R key on the keyboard
	std::ofstream file(SETTINGS_FILE_NAME);
	nlohmann::json newJson = nlohmann::json();
	newJson["encryption"] = dS::settings["encryption"];
	newJson["username"] = dS::username;
	file << newJson;
	file.close();
}