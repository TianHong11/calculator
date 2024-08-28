//
// Created by tianh on 2/14/2023.
//

#include "Font.h"

sf::Font Font::font;
void Font::loadFont()
{
    font.loadFromFile("arial.ttf");
}

sf::Font &Font::getFont()
{
    loadFont();
    return font;
}
