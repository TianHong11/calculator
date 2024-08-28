//
// Created by tianh on 2/15/2023.
//

#ifndef SFML_PROJECT_ALLBUTTON_H
#define SFML_PROJECT_ALLBUTTON_H
#include <SFML/Graphics.hpp>
#include "Button.h"
#include <vector>
#include <iostream>
#include "Position.h"
#include "Screen.h"
class AllButton: public sf::Drawable
{
private:
    std::vector<Button> allButton;

    std::vector<std::string> character= {"C","(",")","/",
                                         "7","8","9","*",
                                         "4","5","6","-",
                                         "1","2","3","+",
                                         "0","="};

public:
    AllButton();
    void addButton(std::string character);
    void setPosition();
    int size() const;
    Button operator[](int i);
    Button operator[](int i) const;

    std::vector<Button>& getAllButtons();

    void eventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
};


#endif //SFML_PROJECT_ALLBUTTON_H
