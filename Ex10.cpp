#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return 0;
    }
}

string infixToPostfix(string expression) {
    stack<char> operators;
    string postfix = "";

    for (char c : expression) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Discard the '('
        } else {
            while (!operators.empty() && operators.top() != '(' && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

string infixToPrefix(string expression) {
    reverse(expression.begin(), expression.end()); // Reverse the input expression
    stack<char> operators;
    string prefix = "";

    for (char c : expression) {
        if (isalnum(c)) {
            prefix += c;
        } else if (c == ')') {
            operators.push(c);
        } else if (c == '(') {
            while (!operators.empty() && operators.top() != ')') {
                prefix += operators.top();
                operators.pop();
            }
            operators.pop(); // Discard the ')'
        } else {
            while (!operators.empty() && operators.top() != ')' && precedence(operators.top()) > precedence(c)) {
                prefix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        prefix += operators.top();
        operators.pop();
    }

    reverse(prefix.begin(), prefix.end()); // Reverse the result
    return prefix;
}

int main() {
    //string infixExpression = "a+(a*b)";
    string infixExpression;
    cin>>infixExpression;
    cout << "Infix expression: " << infixExpression << endl;
    cout << "Postfix expression: " << infixToPostfix(infixExpression) << endl;
    cout << "Prefix expression: " << infixToPrefix(infixExpression) << endl;

    return 0;
}
