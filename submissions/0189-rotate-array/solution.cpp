class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = size - (k % size);

        for ( int i = 0 ; i < size+k ; i++ ){

            int index = i % size;

            if( i > size - 1 ) nums.push_back( nums[index] );
            
        }

        nums.erase( nums.begin(), nums.begin() + k );
    }
};
