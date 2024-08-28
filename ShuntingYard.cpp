//
// Created by tianh on 2/21/2023.
//

#include "ShuntingYard.h"
std::stack<char> ShuntingYard:: stack= {};
std::string ShuntingYard::queue= {};

std::string ShuntingYard::doPostfix(const std::string& equation)
{
    for(int i=0;i<equation.size();i++)
    {
        if (isdigit(equation[i]))
        {
            queue.push_back(equation[i]);
            std::cout << equation[i]<<" Number go to Queue" << std::endl;
        }
        else
        {
             if (equation[i] == '(') {
                stack.push(equation[i]);
                std::cout << equation[i]<<" Open parenthesis to stack" << std::endl;
            }
             else if (equation[i] == ')') {
                while (stack.top() != '(' && !stack.empty()) {
                    queue.push_back(stack.top());
                    stack.pop();
                    std::cout << equation[i]<<" Closed parenthesis" << std::endl;

                }
                stack.pop();
            }
//            else if (stack.empty()) {
//                stack.push(equation[i]);
//                std::cout <<equation[i] <<" if nothing in stack just push operator"<<std::endl;
//            }
            else if (stack.empty() || precedence(stack.top()) >= precedence(equation[i])) {
//                queue.push_back(stack.top());
//                stack.pop();
                while (!stack.empty() && stack.top() != '(' && precedence(stack.top()) >= precedence(equation[i]) )
                {
                    queue.push_back(stack.top());
                    stack.pop();
                    std::cout <<equation[i] <<" Higher presidence in stack so pop it first" << std::endl;
                }
                stack.push(equation[i]);
                std::cout<<equation[i]<< " push to stack the lower presidence op"<<std::endl;
            }
            else
             {
                std::cout<<equation[i]<<" Operator in the top of stack lower presidence so just push it"<<std::endl;
                stack.push(equation[i]);
             }
        }

    }
        while (!stack.empty()) {
            queue.push_back(stack.top());
            stack.pop();
            std::cout<<"pop everything in stack"<<std::endl;
        }

    return queue;
}
int ShuntingYard::precedence(char op)
{
    switch(op)
    {
        case '+':
        case '-':
            return 1;
        case '/':
        case '*':
            return 2;
        default:
            return 3;
    }
}
