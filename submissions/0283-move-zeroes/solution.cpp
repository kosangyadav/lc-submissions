class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroes = 0;
        for( int i = 0; i < nums.size(); i++){
            if( nums[i] == 0 ){
                nums.erase(nums.begin() + i);
                zeroes++;
                i--;
            }
        }

        for(int i = 0; i < zeroes; i++){
            nums.push_back(0);
        }
    }
};
