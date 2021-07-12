#pragma once
#include <all.h>
#define DEFAULT_UDP_PORT 54321

namespace nt{
	extern bool processCommands(std::string);
	extern sf::Packet encryptMessage(std::string);
	extern std::pair<std::string,std::string> decryptMessage(sf::Packet);
}