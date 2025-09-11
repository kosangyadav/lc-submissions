class TimeMap {
    unordered_map<int, pair<string, string>> timeKeyValue;
    vector<int> timeStamps;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        this->timeKeyValue.insert({timestamp, {key, value}});
        this->timeStamps.push_back(timestamp);
    }

    string get(string key, int timestamp) {
        auto it = this->timeKeyValue.find(timestamp);
        if (it != this->timeKeyValue.end() && it->second.first == key)
            return it->second.second;

        for (int i = timeStamps.size() - 1; i >= 0; i--) {
            if (timeStamps[i] < timestamp) {
                auto it = this->timeKeyValue.find(timeStamps[i]);
                if (it != this->timeKeyValue.end() && it->second.first == key)
                    return it->second.second;
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
