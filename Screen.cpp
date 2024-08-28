//
// Created by tianh on 2/14/2023.
//

#include "Screen.h"

Screen::Screen()
{
    screen.setSize({300, 100});
    screen.setPosition({0,20});
}

void Screen::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(screen);
}

sf::FloatRect Screen::getGlobalBounds() const
{
    return screen.getGlobalBounds();
}

//std::string Screen::getEquation(const AllButton &allButton, sf::RenderWindow &window) {
//    std::string equation;
//    for (int i = 0; i < allButton.size(); i++)
//    {
//        if (MouseEvent::isClicked(allButton[i],window))
//        {
//            equation.push_back(allButton[i].getText());
//        }
//    }
//}