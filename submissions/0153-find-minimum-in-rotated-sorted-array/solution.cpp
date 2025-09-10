class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size() - 1, mid;

        if (nums[start] <= nums[end])
            return nums[0];

        while (start <= end) {

            mid = (start + end) / 2;

            if ( mid != 0 && mid!= nums.size() -1 && nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1] &&
                nums[mid] > nums[start])
                start = mid + 1;
            else if ( mid != 0 && mid!= nums.size() -1 && nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1] &&
                     nums[mid] < nums[end])
                end = mid - 1;
            else {
                if (nums[mid] > nums[mid + 1])
                    return nums[mid + 1];
                else if (nums[mid - 1] > nums[mid])
                    return nums[mid];
            }
        }
        return -1;
    }
};
