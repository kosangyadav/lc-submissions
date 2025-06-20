class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecutiveOnes = 0;
        int nextMaxConsecutiveOnes = 0;
        for( int i = 0; i < nums.size(); i++ ){
            if( nums[i] == 1 ) {
                nextMaxConsecutiveOnes++;
                if( maxConsecutiveOnes < nextMaxConsecutiveOnes ) maxConsecutiveOnes = nextMaxConsecutiveOnes;
            }
            else if ( nums[i] == 0 ) nextMaxConsecutiveOnes = 0;

            // cout<<maxConsecutiveOnes<<" "<<nextMaxConsecutiveOnes<<endl;
        }
        return maxConsecutiveOnes;
    }
};
