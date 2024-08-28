//
// Created by tianh on 2/15/2023.
//

#include "AllButton.h"

AllButton::AllButton()
{
    for(int i=0; i<character.size();i++)
    {
        addButton(character[i]);
    }
    setPosition();
}

std::vector<Button> &AllButton::getAllButtons() {
    return allButton;
}

void AllButton::addButton(std::string character)
{
    Button btn(character);

    allButton.emplace_back(btn);

}

void AllButton::setPosition()
{
    Screen screen;
    for(int i=1;i<allButton.size();i++)
    {
        Position::buttonBelow(screen,allButton[0],10);
        if(i%4 ==0)
        {
            Position::buttonBelow(allButton[i-4], allButton[i], 20);
        }
        else
        {
            Position::buttonRight(allButton[i-1],allButton[i], 20);
        }
    }
}

Button AllButton::operator[](int i)
{
    return allButton[i];
}

Button AllButton::operator[](int i) const
{
    return allButton[i];
}

void AllButton::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    for(int i=0; i<allButton.size(); ++i)
    {
        window.draw(allButton[i]);
    }
//    window.draw(screen);
}

int AllButton::size() const {
    return allButton.size();
}

void AllButton::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    for(int i=0; i<allButton.size();i++)
    {
        allButton[i].eventHandler(window,event);
    }
}
