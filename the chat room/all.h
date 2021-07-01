#pragma once
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#define SETTINGS_FILE_NAME "settings.set"
#define DEFAULT_ENCRYPTION NULL // this expands to 0, which is an int
#define DEBUG_DRAW_COLOR sf::Color::Green

//include all predeclarations
#include <PreDecl_ui.h>
#include <PreDecl_openPage.h>
#include <PreDecl_dataStore.h>

// include all actual header files.
#include <ui.h>
#include <dataStore.h>
#include <openPage.h>