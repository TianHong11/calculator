//
// Created by tianh on 2/21/2023.
//

#ifndef SFML_PROJECT_SHUNTINGYARD_H
#define SFML_PROJECT_SHUNTINGYARD_H
#include <iostream>
#include <stack>
#include <queue>

class ShuntingYard
{
private:
    static std::stack<char> stack;
    static std::string queue;
public:
    static std::string doPostfix(const std::string& equation);
    static int precedence(char op);
};


#endif //SFML_PROJECT_SHUNTINGYARD_H
