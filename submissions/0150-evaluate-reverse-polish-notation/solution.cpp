class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> numbers;

        for (int i = 0; i < tokens.size(); i++) {

            if (!numbers.empty() && (tokens[i] == "+" || tokens[i] == "-" ||
                                     tokens[i] == "*" || tokens[i] == "/")) {

                int a = numbers.top();
                numbers.pop();
                int b = numbers.top();
                numbers.pop();

                if (tokens[i] == "+")
                    numbers.push(b + a);
                else if (tokens[i] == "-")
                    numbers.push(b - a);
                else if (tokens[i] == "*")
                    numbers.push(b * a);
                else
                    numbers.push(b / a);
            } else
                numbers.push(stoi(tokens[i]));
        }

        return numbers.top();
    }
};
