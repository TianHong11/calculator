//
// Created by tianh on 2/21/2023.
//

#include "RPN.h"

int RPN::evaluatePostFix(const std::string& postFix)
{
    static std::stack<int> stack;
    for(int i=0; i<postFix.size(); i++)
    {
        if(isdigit(postFix[i]))
        {
            stack.push(postFix[i]-'0');
            std::cout<<"Push to stack"<< postFix[i]<<std::endl;
        }
        else
        {
            std::cout<<"operator"<< postFix[i]<<std::endl;
            int temp= stack.top();
            stack.pop();
            int temp2= stack.top();
            stack.pop();
            std::cout<< temp2 <<" "<< temp<<std::endl;
            stack.push(calculate(const_cast<char &>(postFix[i]), temp2, temp));

        }
    }
    return stack.top();
}

int RPN::calculate(char& op, int& left, int& right)
{
    switch (op)
    {
        case '/':
            return left/right;
        case '*':
            return left*right;
        case '+':
            return left+right;
        case '-':
            return left-right;
        default: return 0;

    }
}
