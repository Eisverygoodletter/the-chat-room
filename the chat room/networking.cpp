#include <all.h>
#include <regex>
#include "networking.h"

bool nt::processCommands(std::string inputStr) {
	return false; // no commands currently TODO
}

sf::Packet nt::encryptMessage(std::string inputStr) {
	sf::Packet ret;
	std::string sendoutStr = inputStr;
	sendoutStr.append(ENCRYPTOR_OVERRIDE);
	for (std::string::size_type i = 0; i < sendoutStr.length(); ++i) {
		sendoutStr[i] += dS::settings["encryption"];
	}
	ret << dS::username << sendoutStr;
	return ret;
}

std::pair<std::string,std::string> nt::decryptMessage(sf::Packet inputPacket) {
	std::string ret;
	std::string retUsername;
	inputPacket >> retUsername >> ret;
	std::cout << retUsername << " : " << ret << '\n';
	for (std::string::size_type i = 0; i < ret.length(); ++i) {
		ret[i] -= dS::settings["encryption"];
	}
	if (ret.find(ENCRYPTOR_OVERRIDE) == std::string::npos) {
		ret = "undecryptable string detected. May be wrong encryption channel\n";
	}
	else {
		// note that in this statement, ENCRYPTOR_OVERRID* will be replaced by the encryptor override keyword
		// this means that it will remove the encryptor override thing from the string before presenting
		// itself to the user
		ret = ret.substr(0, ret.size() - ENCRYPTOR_OVERRIDE_SIZE);
	}
	std::cout << retUsername << ':' << ret << '\n';
	return std::pair<std::string,std::string>(retUsername,ret);
}