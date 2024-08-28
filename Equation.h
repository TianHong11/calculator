//
// Created by tianh on 3/4/2023.
//

#ifndef SFML_PROJECT_EQUATION_H
#define SFML_PROJECT_EQUATION_H

#include <SFML/Graphics.hpp>
#include "Font.h"
#include "iostream"

class Equation :public sf::Drawable
{
private:
    sf::Text equationS;
    std::string equation;
public:
    Equation();
    void updateText();
    void push(const std::string& character);
    void updateEq();
    void clear();
    void setPosition(float x, float y);
    const std::string& getText();
    void setText(const std::string& text);
    sf::FloatRect getGlobalBounds() const;
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void getPosition();
};


#endif //SFML_PROJECT_EQUATION_H
