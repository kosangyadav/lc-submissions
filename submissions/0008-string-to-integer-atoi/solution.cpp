class Solution {
public:
    int myAtoi(string s) {
        long long result = 0;
        bool leading = true;
        int sign = 1;

        for(int i = 0; i < s.length(); i++){
            cout<<"result: "<< result<<endl;
            // if( 48 <= s[i] && s[i] <= 57 ){
            if ( 0 <= s[i]-48 && s[i]-48 <= 9 ){
                if(leading) leading = false;
                if( result*10 + s[i]-48 > INT_MAX && sign == 1 ) return INT_MAX;
                if( result*10 + s[i]-48 > INT_MAX && sign == -1 ) return INT_MIN;
                result = result*10 + s[i]-48;
            }
            // else if( 57 < s[i] ) break;
            else if( leading && s[i] < 46 ){
                if( s[i] == ' ' ) continue;
                // if( s[i] == "+" )
                else if( s[i] == '-') sign = -1;

                leading = false;
                continue;
            }
            else break;
        }
        return result*sign;
    }
};
