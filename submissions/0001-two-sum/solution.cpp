class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size =nums.size();
        unordered_map<int, int> hash;
        for( int i = 0; i < size; i++){
            hash[nums[i]] = i;
        }
        for( int i = 0; i < size; i++){
            int complement = target - nums[i];
            if( hash.find(complement) != hash.end() && hash[complement] != i ) return { i, hash[complement] };
        }
        return { -1 };
    }
};
