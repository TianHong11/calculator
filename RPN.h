//
// Created by tianh on 2/21/2023.
//

#ifndef SFML_PROJECT_RPN_H
#define SFML_PROJECT_RPN_H

#include "ShuntingYard.h"
#include <cmath>
class RPN
{

public:
    static int evaluatePostFix(const std::string& postFix);
    static int calculate(char& op, int& left, int& right);
};


#endif //SFML_PROJECT_RPN_H
