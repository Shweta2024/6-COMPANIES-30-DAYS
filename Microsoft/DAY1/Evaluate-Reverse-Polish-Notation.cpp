// Evaluate Reverse Polish Notation
/*
Intuition :-
1) Traverse the given array from left to right to get the current string.
2) If the current string is an operand, then simply convert it to integer and push it into the stack.
3) If the current string is an operator, then pop out top two values from the stack & compute the new value
 and push th new value back into the stack.
4) Finally return the top value of the stack.

Time Complexity = O(n), for traversing the tokens array
Space Complexity = O(1), since we aren't using any extra space
*/

class Solution
{
public:
    // function to calculate the current value
    int calculate(int first, int second, string current)
    {
        if (current == "+")
            return second + first;

        else if (current == "-")
            return second - first;

        else if (current == "/")
            return second / first;

        else
            return second * first;
    }

    // function to check if current string is an operator or operand
    bool isOperand(string current)
    {
        if (current == "+" || current == "-" || current == "/" || current == "*")
            return false;
        return true;
    }

    int evalRPN(vector<string> &tokens)
    {
        int ans = 0;
        stack<int> stk;
        int n = tokens.size();
        for (int index = 0; index < n; index++)
        {
            string current = tokens[index];

            // if current string is an operand, then push it into the stack
            if (isOperand(current))
                stk.push(stoi(current));

            // otherwise its an operator
            // so pop out two elements from stack and compute the value
            // then store the new value back into the stack
            else
            {
                int first = stk.top();
                stk.pop();
                int second = stk.top();
                stk.pop();

                int currentVal = calculate(first, second, current);
                stk.push(currentVal);
            }
        }
        return stk.top();
    }
};