class Solution {
public:
    int trap(vector<int>& height) {
        int start = -1, last = -1, count = 0;

        for (int i = 0; i < height.size(); i++) {

            if (start != -1 && height[i] < height[start])
                count += height[start] - height[i];
            else
                start = i;
        }

        for (int j = height.size() - 1; j > start; j--) {

            if (last == -1 || height[j] > height[last])
                last = j;

            count -= height[start] - height[last];
        }

        return count;
    }
};
