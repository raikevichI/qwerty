// dz_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "stack.hpp"
#include <string>

bool checkBalanceBrackets(const std::string& text, const std::size_t maxDeep)
{
    StackArray<char> brackets(text.size());

    for (char c : text) {
        char openBracket = '\0';
        switch (c) {
        case '(':
        case '[':
        case '{':
            if (brackets.full())
                return false;
            openBracket = c;
            brackets.push(c);
            break;
        case ')':
            openBracket = '(';
            if (brackets.isEmpty() || brackets.pop() != openBracket)
                return false;
            break;
        case ']':
            openBracket = '[';
            if (brackets.isEmpty() || brackets.pop() != openBracket)
                return false;
            break;
        case '}':
            openBracket = '{';
            if (brackets.isEmpty() || brackets.pop() != openBracket)
                return false;
            break;
        default:
            break;
        }
    }

    return brackets.isEmpty();
}
int main()
{
    //std::cout << checkBalanceBrackets("(x(x{[x]}x)x)", 9) << std::endl;
    StackArray<int> stack1(6);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.pop();
    stack1.pop();
    stack1.pop();

    StackArray<int> stack2(stack1); // конструктор копирования
 
    return 0;
}

