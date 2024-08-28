//
// Created by tianh on 2/14/2023.
//

#ifndef SFML_PROJECT_BUTTON_H
#define SFML_PROJECT_BUTTON_H

#include <SFML/Graphics.hpp>
#include "Font.h"
#include "Position.h"
#include "MouseEvent.h"
#include <iostream>
#include "Equation.h"
#include <functional>

class Button: public sf::Drawable
{
private:
    sf::CircleShape circle;
    sf::Text text;
    sf::Color original={212,212,0}, hovered=sf::Color::White,
    originalText=sf::Color::Black, hoveredText= {212,212,0};

    std::string character;

    Equation equation;
// By Tutor (Adam G.)
    std::function<void(std::string)> callback;

public:
    Button();
    Button( std::string& text);
    Button(const std::string& text, const sf::Color& textColor, const sf::Color& backGroundColor);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setBackGroundColor(const sf::Color& color);
    void setTextColor(const sf::Color& color);
    void setText(const std::string text);
    std::string getText() const;
    char getButtonText() const;

    void setCallback(std::function<void(std::string)> cb); // By Tutor (Adam G.)

    void setPosition(float x, float y);
//    void setPosition(float x, float y) const;

    void setSize(float size);
    sf::FloatRect getGlobalBounds() const;
    void init(const std::string &text, const sf::Color &textColor, const sf::Color &backGroundColor);
    Button operator()(std::string character);

    void eventHandler(sf::RenderWindow& window, sf::Event event);

};


#endif //SFML_PROJECT_BUTTON_H
