class Solution {
public:
    bool isValid(string s) {

        if(s.size() == 1) return false;

        stack<char> brackets;

        for (char c : s) {

            if (c == '(' || c == '[' || c == '{')
                brackets.push(c);
            else if ( !brackets.empty() && (c - brackets.top() == 1 || c - brackets.top() == 2)){
                // cout<<brackets.top()<<" ";
                brackets.pop();
                }
            else
                return false;
        }

        if (brackets.empty())
            return true;
        else
            return false;
    }
};
