/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        map<UndirectedGraphNode *, UndirectedGraphNode *> cloneMap;
        stack<UndirectedGraphNode *> worklist;
        UndirectedGraphNode *clone = new UndirectedGraphNode(node->label);
        cloneMap[node] = clone;
        worklist.push(node);
        while (!worklist.empty()) {
            UndirectedGraphNode *curr = worklist.top();
            worklist.pop();
            assert(cloneMap.find(curr) != cloneMap.end());
            for (auto &each : curr->neighbors) {
                if (cloneMap.find(each) == cloneMap.end()) {
                    cloneMap[each] = new UndirectedGraphNode(each->label);
                    worklist.push(each);
                }
                cloneMap[curr]->neighbors.emplace_back(cloneMap[each]);
            }
        }
        return clone;
    }
};