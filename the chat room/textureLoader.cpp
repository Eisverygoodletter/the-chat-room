#pragma once
#include "textureLoader.h"
#include <all.h>



void tL::loadTextures() {
	ui::checkBox::checkedTexture.loadFromFile(TEXTURE_CHECKBOX_CHECKED);
	ui::checkBox::uncheckedTexture.loadFromFile(TEXTURE_CHECKBOX_UNCHECKED);
	ui::textButton::defaultFont.loadFromFile("Arial.ttf");
}