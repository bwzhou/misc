class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> visited;
        deque<string> path;
        deque<int> depth;
        visited.insert(start);
        path.push_back(start);
        depth.push_back(1);
        while (!path.empty()) {
            string curr = path.front();
            int currDepth = depth.front();
            for (char &each : curr) {
                char copy = each;
                for (char i = 'a'; i <= 'z'; ++i) {
                    each = i;
                    if (dict.find(curr) != dict.end() && visited.find(curr) == visited.end()) {
                        visited.insert(curr);
                        path.push_back(curr);
                        depth.push_back(currDepth + 1);
                        if (curr == end) {
                            return depth.back();
                        }
                    }
                }
                each = copy;
            }
            path.pop_front();
            depth.pop_front();
        }
        return 0;
    }
};
