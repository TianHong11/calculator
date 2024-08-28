//
// Created by tianh on 2/14/2023.
//

#ifndef SFML_PROJECT_CALCULATOR_H
#define SFML_PROJECT_CALCULATOR_H

#include <SFML/Graphics.hpp>
#include "AllButton.h"
#include "Screen.h"
class Calculator:public sf::Drawable
{
private:
    std::vector<std::string> character= {"C","(",")","/",
                                         "7","8","9","*",
                                         "4","5","6","-",
                                         "1","2","3","+",
                                         "0","="};
    Screen screen;
    AllButton allButton;
public:
    Calculator();
    void setPosition();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //SFML_PROJECT_CALCULATOR_H
