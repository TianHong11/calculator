//
// Created by tianh on 2/21/2023.
//

#ifndef SFML_PROJECT_MOUSEEVENT_H
#define SFML_PROJECT_MOUSEEVENT_H

#include <SFML/Graphics.hpp>
#include <iostream>
class MouseEvent
{
public:
    template<class T>
    static bool isHovered(const T& obj, sf::RenderWindow& window);

    template<class T>
    static bool isClicked(const T& obj, sf::RenderWindow& window);

};
#include "MouseEvent.cpp"


#endif //SFML_PROJECT_MOUSEEVENT_H
