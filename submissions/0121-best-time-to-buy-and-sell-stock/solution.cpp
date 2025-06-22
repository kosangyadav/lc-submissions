class Solution {
public:
    int maxProfit(vector<int>& nums) {
        
        int buy = nums[0], profit = 0;
        for( int i = 0; i < nums.size(); i++ ){
            if( buy > nums[i] ) buy = nums[i];
            else if( nums[i] - buy > profit ) profit = nums[i] - buy;
        }

        return profit;
    }
};
