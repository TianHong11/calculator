//
// Created by tianh on 2/15/2023.
//

#ifndef SFML_PROJECT_POSITION_H
#define SFML_PROJECT_POSITION_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
class Position
{
public:
    template <typename T, typename S>
    static void buttonLeft(const T& leftB, S& rightB, float space);
    template <typename T, typename S>
    static void buttonRight(const T& leftB, S& rightB,float space);
    template <typename T, typename S>
    static void buttonTop(const T& leftB, S& rightB, float space);
    template <typename T, typename S>
    static void buttonBelow(const T& leftB, S& rightB, float space);
    template <typename T, typename S>
    static void centerToScreen(const T& screen, S& numbers);
    template <typename T>
    static void centerText(const T &obj, sf::Text &text);
    template<typename T, typename S>
    static void bottomLeft(const T &window, S &button);

    template<typename T, typename S>
    static void eqToScreen(const T &screen, S &equation);

};
#include "Position.cpp"

#endif //SFML_PROJECT_POSITION_H
