class Log {
public:
    Log() {
        sum = 0;
    }

    // Records a hit happend just now
    void logHit() {
        int now = time();
        update(now);
        ++counters[index].first;
        ++sum;
        counters[index].second = now;
    }

    // Returns the total number of hits over the last five minutes
    int getHits() {
        int now = time();
        update(now);
        return sum;
    }
private:
    // Zeros expired counters according to current time
    void update(int now) {
        int index = now % counters.size();
        if (counters[index].second != now) {
            if (now - counters[last].second < counters.size()) {
                for (int i = last + 1; i != index + 1;
                     i = (i + 1) % counters.size()) {
                    sum -= counters[i];
                    counters[i] = 0;
                }
            } else {
                for (int i = 0; i < counters.size(); ++i) {
                    counters[i] = 0;
                }
                sum = 0;
            }
        }
        last = index;
    }

    // A circular array of counters each for one second of the last five minutes
    vector<pair<int, int>> counters(300);
    // A cached value for total number of hits
    int sum;
    // Index of the last hit
    int last;
};
