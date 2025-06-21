class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int>hash;
        for(int i = 0; i < nums.size(); i++){
            hash[nums[i]]++;
        }

        nums.clear();
        
        for( int i = 0; i < hash[0]; i++){
            nums.push_back(0);
        }
        for( int i = 0; i < hash[1]; i++){
            nums.push_back(1);
        }
        for( int i = 0; i < hash[2]; i++){
            nums.push_back(2);
        }
    }
};
