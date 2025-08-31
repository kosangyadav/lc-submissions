class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int carFleets = 1;
        map<int, float, greater<int>> timeMap;

        if (position.size() == 1) {
            return carFleets;
        }

        for (int i = 0; i < position.size(); i++) {

            float timeToReachTarget = float(target - position[i]) / float(speed[i]);

            timeMap.insert({position[i], timeToReachTarget});
        }

        // for (auto it : timeMap) {
        //     cout << it.second << " ";
        // }

        auto i = timeMap.begin();

        auto j = next(i);

        while ( j != timeMap.end() ) {

            if (j->second <= i->second) {
                j++;
            } else{
                i=j;
                j++;
                carFleets++;
            }
        }

        return carFleets;
    }
};
