class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int size = temperatures.size();

        vector<int> days(size, 0);

        stack<int> laterIndexes;

        int i = 0;

        while (i < size) {

            while (!laterIndexes.empty() &&
                   temperatures[i] > temperatures[laterIndexes.top()]) {

                days[laterIndexes.top()] = i - laterIndexes.top();

                laterIndexes.pop();
            }

            if ( i + 1 < size && temperatures[i] < temperatures[i + 1]) {
                days[i] = 1;
                i++;
            } else {
                laterIndexes.push(i);
                i++;
            }
        }

        while (!laterIndexes.empty()) {

            days[laterIndexes.top()] = 0;

            laterIndexes.pop();
        }

        days[size - 1] = 0;

        return days;
    }
};
