//
// Created by tianh on 3/4/2023.
//

#include "Equation.h"

Equation::Equation()
{
    updateText();
}

void Equation::updateText() {
    equationS.setFont(Font::getFont());
    equationS.setString(equation);
    equationS.setCharacterSize(50);
    equationS.setFillColor(sf::Color::Black);
//    equationS.setPosition(100,100);
}

void Equation::push(const std::string &character)
{
    equation+=character;
}

const std::string &Equation::getText() {
    return equation;
}

void Equation::setText(const std::string &text) {
    equationS.setString(text);
}

void Equation::clear() {
    equation = "";
    updateEq();
}

void Equation::updateEq()
{
    equationS.setString(equation);
}

void Equation::setPosition(float x, float y)
{
    equationS.setPosition(x,y);
}

void Equation::getPosition() {
    std::cout<< equationS.getPosition().x <<" and "<< equationS.getPosition().y<<std::endl;
}

sf::FloatRect Equation::getGlobalBounds() const
{
    return equationS.getGlobalBounds();
}

void Equation::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(equationS);
}
