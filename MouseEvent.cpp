//
// Created by tianh on 2/21/2023.
//

#ifndef SFML_PROJECT_MOUSEEVENT_CPP
#define SFML_PROJECT_MOUSEEVENT_CPP
#include "MouseEvent.h"

template<class T>
bool MouseEvent::isHovered(const T &obj, sf::RenderWindow& window) {
    return  obj.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window));
    //sf::Mouse::isButtonPressed(sf::Mouse::Left)
}

template<class T>
bool MouseEvent::isClicked(const T &obj, sf::RenderWindow &window) {
    return  sf::Mouse::isButtonPressed(sf::Mouse::Left) && obj.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window)) ;
}

#endif //SFML_PROJECT_MOUSEEVENT_CPP
