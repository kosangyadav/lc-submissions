#include<vector>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for ( int j=0; j < nums.size(); j++ ){
            if( nums[i] != nums[j] ) nums[++i] = nums[j];
        }

        int result = i + 1;

        for( i++ ; i < nums.size(); i++ ){
            nums[i] = -1;
        }
        
        return result;
    }
};
