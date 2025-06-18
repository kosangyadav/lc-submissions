class Solution {
public:
    bool check(vector<int>& nums) {

        int size = nums.size();
        int transition = 1;

        for (int i = 0; i < size ; i++){
            int next = (i + 1) % size;
            if( nums[i] > nums[next] ){
                if( transition == 1 && nums[1] >= nums[next] ){
                    transition--;
                }
                else return false;
            }
        }

        return true;
    }
};
