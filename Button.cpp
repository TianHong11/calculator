//
// Created by tianh on 2/14/2023.
//

#include "Button.h"

//std::string Button::equation;

Button::Button(): Button("=", sf::Color::White,{255,149,0})
{

}

Button::Button( std::string& text)
:Button(text, sf::Color::Black, {212,212,0})
{
    character = text;
}

Button::Button(const std::string &text, const sf::Color &textColor, const sf::Color &backGroundColor)
{
    init(text,textColor,backGroundColor);

}

void Button::setBackGroundColor(const sf::Color &color)
{
    circle.setFillColor(color);
}

void Button::setTextColor(const sf::Color &color)
{
    text.setFillColor(color);
}

void Button::setText(const std::string text)
{
    this->text.setString(text);
}

 std::string Button::getText() const
{
    return text.getString();
}

void Button::setPosition(float x, float y)
{
    circle.setPosition(x,y);
    Position::centerText(circle,text);
}

//void Button::setPosition(float x, float y) const
//{
//    circle.setPosition(x,y);
//    Position::centerText(circle,text);
//}


void Button::init(const std::string &text, const sf::Color &textColor, const sf::Color &backGroundColor)
{
    this->text.setFont(Font::getFont());
    this->text.setString(text);
    this->text.setFillColor(textColor);

    this->text.setCharacterSize(48);
    circle.setFillColor(backGroundColor);

    circle.setRadius(30);
    Position::centerText(circle,this->text);

//    equationS.setFillColor(sf::Color::Black);
//    equationS.setString(equation);
//    equationS.setCharacterSize(48);
//    equationS.setFont(Font::getFont());
}

sf::FloatRect Button::getGlobalBounds() const
{
    return circle.getGlobalBounds();
}

void Button::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvent::isHovered(circle, window))
    {
        circle.setFillColor(hovered);
        text.setFillColor(hoveredText);
    }
    else
    {
        circle.setFillColor(original);
        text.setFillColor(originalText);
    }

    if(MouseEvent::isClicked(circle, window) && event.type == sf::Event::MouseButtonPressed)
    {
        // call a function and pass the text or character.
        ////how does it know what character this circle has?
        //equation += character;
        //equation.push(character);

        if (callback != nullptr) {
            callback(character); // By Tutor (Adam G.)
        }

        circle.setFillColor(hovered);
        text.setFillColor(hoveredText);
    }
    else
    {
        //circle.setFillColor(original);
        //text.setFillColor(originalText);
    }
}

void Button::setCallback(std::function<void(std::string)> cb) {
    callback = std::move(cb);
}
//void Button::updateEq()
//{
//    equationS.setString(equation);
//}

Button Button::operator()(std::string character) {
    return Button(character);
}
void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
//    window.draw(equationS);
    window.draw(circle);
    window.draw(text);
}
