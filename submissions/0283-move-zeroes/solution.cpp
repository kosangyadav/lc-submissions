class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        for( ; i<nums.size() && j<nums.size(); i++ ){
            if(nums[i] == 0){
                for( j=i+1; j < nums.size(); j++ ){
                    if( nums[j] != 0 ){
                        nums[i] = nums[j];
                        nums[j] = 0;
                        break;
                    }
                }
            }
        }
    }
};
