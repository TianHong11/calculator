//
// Created by tianh on 2/14/2023.
//

#include "Application.h"

void Application::run()
{
//    std::cout<<RPN::evaluatePostFix(ShuntingYard::doPostfix("3+4"));

    sf::RenderWindow window({300,550,32}, "Calculator");

       AllButton allButton;

    Equation equation;

// By Tutor (Adam G.)

    for (auto& btn : allButton.getAllButtons()) //what does the condition of this for loop do?
    {
        //// how does btn knows what is the button I am clicking?
        if (btn.getText() == "C") { // clear equation
            btn.setCallback([&](const std::string& c) {
                equation.clear();
            });
        } else if (btn.getText() == "=") { // solve button
            btn.setCallback([&](const std::string& c) {
                equation.setText(std::to_string(RPN::evaluatePostFix(ShuntingYard::doPostfix(equation.getText()))));
            });
        } else { // all other operations
            btn.setCallback([&](const std::string& c) {
                equation.push(c);
                equation.updateEq();
            });
        }
    }

    Screen screen;
    Position::eqToScreen(screen,equation);
//    equation.getPosition();

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
            {
                window.close();
            }
            ////Only thing missing is that when I click the button I cannot get the character
            allButton.eventHandler(window,event);
        }
        //equation.updateEq();

        window.clear();
        window.draw(screen);
        window.draw(equation);
        window.draw(allButton);
        window.display();
    }
}
