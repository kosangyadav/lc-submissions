class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0, left = 0, right = 0;
        unordered_map<int, int> abc = {};
        while( right < s.size() ){
            abc[s[right]]++;
            if ( abc[s[right]] > 1 ){
                // abc[s[right]]--;
                // left++;
                // if(s[left] == s[right] && left != right) left = right;
                while(left<right){
                    abc[s[left]]--;
                    left++;
                    if(abc[s[left - 1]] == abc[s[right]]) break;
                }
            } else{
                maxLength = max(maxLength, right - left + 1);
            }
            right++;
        }
        return maxLength;
    }
};
