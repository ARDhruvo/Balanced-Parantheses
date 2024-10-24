/*
 * @Author: ARDhruvo/Kashikizu
 * Initial Completion Date: 24/10/2024 (DD/MM/YYYY)
 */

/* The main strategy is:
 * 1. If the character is an opening paranthesis then we push it in the stack
 *
 *
 * 2. IF the character is a closing paranthesis and:
 *
 * 2.1. -> If the stack is empty then its not balanced <-
 *
 * 2.2. If the stack is not empty:
 * 2.2.1. -> If the top of the stack is not the same type of closing paranthesis then its not balanced <-
 * 2.2.2. If the top of the stack is the same type of closing paranthesis then we pop
 *
 *
 * 3. If the stack is empty at the end of the loop then it is balanced
 */

#include <bits/stdc++.h>
using namespace std;

bool balanced(string inp)
{
    stack<char> parantheses;
    for (int i = 0; i < inp.size(); i++)
    {
        if ((inp[i] == '(') || (inp[i] == '{') || (inp[i] == '[')) // Case 1
        {
            parantheses.push(inp[i]);
        }
        else if ((inp[i] == ')') || (inp[i] == '}') || (inp[i] == ']'))
        {
            if (parantheses.empty())
            {
                return false; // Case 2.1
            }
            else if (((inp[i] == ')') && (parantheses.top() != '(')) || ((inp[i] == '}') && (parantheses.top() != '{')) || ((inp[i] == ']') && (parantheses.top() != '[')))
            {
                return false; // Case 2.2
            }
            else
            {
                parantheses.pop(); // Pops if parantheses is closed
            }
        }
    }
    if (parantheses.empty()) // Returns true or false for future scalability. Otherwise would have been printed here
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string inp, exp;
    cout << "Enter expression: ";
    getline(cin, inp); // cin fails to take white spaces for some reason
    if (balanced(inp))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not balanced" << endl;
    }
}
