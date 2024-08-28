//
// Created by tianh on 2/15/2023.
//
#ifndef SFML_PROJECT_POSITION_CPP
#define SFML_PROJECT_POSITION_CPP
#include "Position.h"

template<typename T, typename S>
void Position::eqToScreen(const T &screen, S &equation)
{
    sf::FloatRect s= screen.getGlobalBounds();
    sf::FloatRect e= equation.getGlobalBounds();
    equation.setPosition(s.left,s.top+s.height/4);
}

template<typename T, typename S>
void Position::buttonLeft(const T &leftB, S &rightB, float space)
{
    sf::FloatRect l= leftB.getGlobalBounds();
    sf::FloatRect r= rightB.getGlobalBounds();
    rightB.setPosition(l.left-l.width-space, l.top);
}

template<typename T, typename S>
void Position::buttonRight(const T &leftB, S &rightB, float space)
{
    sf::FloatRect l= leftB.getGlobalBounds();
    sf::FloatRect r= rightB.getGlobalBounds();
    rightB.setPosition(l.left+l.width+space, l.top);
}

template<typename T, typename S>
void Position::buttonTop(const T &leftB, S &rightB, float space)
{
    sf::FloatRect l= leftB.getGlobalBounds();
    sf::FloatRect r= rightB.getGlobalBounds();
    rightB.setPosition(l.left, l.top-l.height-space);

}

template<typename T, typename S>
void Position::buttonBelow(const T &leftB, S &rightB, float space)
{
    sf::FloatRect l= leftB.getGlobalBounds();
    sf::FloatRect r= rightB.getGlobalBounds();
    rightB.setPosition(l.left, l.top+l.height+space);
}

template<typename T, typename S>
void Position::centerToScreen(const T &screen, S &numbers)
{

}
template <typename  T>
void Position::centerText(const T &obj, sf::Text &text)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width / 2.0f, textRect.height / 2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width / 2, tRect.top + tRect.height / 2});
}

template<typename T, typename S>
void Position::bottomLeft(const T &window, S &button)
{
    sf::Vector2u w= window.getSize();
    sf::FloatRect b= button.getGlobalBounds();
    button.setPosition(w.x-b.width,w.y-b.height);
}

#endif //SFML_PROJECT_POSITION_CPP