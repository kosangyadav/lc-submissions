class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int size = piles.size() - 1, maxEle = piles[0], k = -1, lastHours = 0;

        if (size == 0) {
            if (piles[0] % h == 0)
                return piles[0] / h;
            else
                return piles[0] / h + 1;
        }

        for (int i = 0; i <= size; i++) {

            maxEle = max(maxEle, piles[i]);
        }

        int start = 1, end = maxEle, mid;
        while (start <= end) {

            mid = (start + end) / 2;

            double instantHours = 0;

            for (int i = 0; i <= size; i++) {
                if (piles[i] % mid == 0)
                    instantHours += piles[i] / mid;
                else
                    instantHours += piles[i] / mid + 1;
            }
            if (instantHours < h) {
                if (instantHours > lastHours) {
                    k = mid;
                    lastHours = instantHours;
                }
                end = mid - 1;
            } else if (instantHours > h)
                start = mid + 1;
            else {
                k = mid;
                lastHours = instantHours;
                end = mid - 1;
            }
        }

        return k;
    }
};
