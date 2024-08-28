//
// Created by tianh on 2/14/2023.
//

#ifndef SFML_PROJECT_SCREEN_H
#define SFML_PROJECT_SCREEN_H

#include  "Font.h"
#include <SFML/Graphics.hpp>
#include "Position.h"
class Screen: public sf::Drawable
{
private:
    sf::RectangleShape screen;

public:
    Screen();
    sf::FloatRect getGlobalBounds() const;


//    std::string getEquation(const AllButton& allButton, sf::RenderWindow& window);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //SFML_PROJECT_SCREEN_H
