class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size() - 1;
        int start = 0, end = size, mid;
        int result = -1;

        if ((nums[0] < nums[size] &&
             (target < nums[0] || nums[size] < target)) ||
            (nums[size] < target && target < nums[0]))
            return result;

        while (start <= end) {

            mid = (start + end) / 2;

            // cout << nums[mid] << endl;

            if (nums[mid] == target) {
                result = mid;
                break;
                // return mid;
            } else if (start == end)
                break;

            if ((0 < mid && nums[mid - 1] > nums[mid] && nums[mid] < target && target <= nums[size]) ||
                (mid < size && nums[mid] > nums[mid + 1] && target < nums[mid] && target <= nums[size]) ||
                (((0 < mid && nums[mid - 1] < nums[mid]) || (mid < size && nums[mid] < nums[mid + 1])) &&
                 ((nums[0] <= nums[mid] && (nums[mid] < target ||
                    (target < nums[mid] && target <= nums[size] && target < nums[0]))) ||
                  (nums[mid] < nums[size] && target > nums[mid] && target <= nums[size]))))
                start = mid + 1;

            else if ((0 < mid && nums[mid - 1] > nums[mid] && nums[mid] < target && target >= nums[0]) ||
                     (mid < size && nums[mid] > nums[mid + 1] && target < nums[mid] && target >= nums[0]) ||
                     (((0 < mid && nums[mid - 1] < nums[mid]) ||
                  (mid < size && nums[mid] < nums[mid + 1])) &&
                      ((nums[mid] <= nums[size] && (nums[mid] > target ||
                         (nums[mid] < target && target >= nums[size]))) ||
                       (nums[0] <= nums[mid] && target < nums[mid] && target >= nums[0]))))
                end = mid - 1;
            else
                break;
            // cout << "start " << start << ", end " << end << endl;
        }

        return result;
    }
};
