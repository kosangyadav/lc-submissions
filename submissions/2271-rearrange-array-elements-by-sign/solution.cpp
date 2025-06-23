class Solution {
public:

    vector<int> rearrangeArray(vector<int>& nums) {

        int size = nums.size();
        int i = 0, p = 0, n = 1;

        vector<int>hash(size);

        for( int i = 0; (p < size || n < size) && i < size; i++ ){

            if( 0 < nums[i] && p < size){
                hash[p] = nums[i];
                p = p + 2;
            }
            else if( nums[i] < 0 && n < size ){
                hash[n] = nums[i];
                n = n + 2;
            }
        }
        return hash;
    }
};
