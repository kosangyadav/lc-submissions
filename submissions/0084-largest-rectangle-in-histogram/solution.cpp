class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<pair<int, int>> heightsCountsPairs;

        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {

            if (heightsCountsPairs.empty() ||
                heights[i] > heightsCountsPairs.top().first)
                heightsCountsPairs.push({heights[i], 1});

            else if (heights[i] == heightsCountsPairs.top().first)
                heightsCountsPairs.top().second++;

            else {
                pair<int, int> poppedElement;
                while (!heightsCountsPairs.empty() &&
                       heights[i] < heightsCountsPairs.top().first) {

                    poppedElement = heightsCountsPairs.top();

                    // cout<<poppedElement.first<<poppedElement.second<<endl;

                    maxArea = max(maxArea,
                                  poppedElement.first * poppedElement.second);
                    heightsCountsPairs.pop();

                    if (!heightsCountsPairs.empty() &&
                        heights[i] < heightsCountsPairs.top().first)
                        heightsCountsPairs.top().second += poppedElement.second;
                }

                if (!heightsCountsPairs.empty() &&
                    heightsCountsPairs.top().first == heights[i])
                    heightsCountsPairs.top().second += poppedElement.second + 1;

                else if ((!heightsCountsPairs.empty() &&
                          heights[i] > heightsCountsPairs.top().first) ||
                         heightsCountsPairs.empty())
                    heightsCountsPairs.push(
                        {heights[i], 1 + poppedElement.second});
            }
        }

        pair<int, int> poppedElement;

        while (!heightsCountsPairs.empty()) {
            poppedElement = heightsCountsPairs.top();
            maxArea = max(maxArea, poppedElement.first * poppedElement.second);
            heightsCountsPairs.pop();
            if (heightsCountsPairs.empty())
                break;
            heightsCountsPairs.top().second += poppedElement.second;
        }

        return maxArea;
    }
};
