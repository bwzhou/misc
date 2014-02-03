#include <random>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using std::default_random_engine;
using std::uniform_int_distribution;
using std::vector;
using std::map;
using std::set;
using std::cout;
using std::endl;
using std::min;

struct Node {
  int id;
  vector<Node*> neighbors;
  Node(int _id) : id(_id) {
  }
};

Node *clone_graph(Node *graph, map<Node *, Node *> &node_clone) {
  if (node_clone.find(graph) != node_clone.end())
    return node_clone[graph];
  Node *dup = new Node(graph->id);
  node_clone[graph] = dup;
  for (vector<Node *>::iterator it = graph->neighbors.begin(),
       ie = graph->neighbors.end(); it != ie; ++it)
    dup->neighbors.push_back(clone_graph(*it, node_clone));
  return dup;
}

void print_graph(Node *graph, set<Node *> &node_visited) {
  if (node_visited.find(graph) != node_visited.end())
    return;
  for (Node *each : graph->neighbors)
    cout << graph->id << "(" << graph << ")->" << each->id << "(" << each << ") ";
  cout << endl;
  node_visited.insert(graph);
  for (vector<Node *>::iterator it = graph->neighbors.begin(),
       ie = graph->neighbors.end(); it != ie; ++it)
    print_graph(*it, node_visited);
}

Node *gen_graph(int numNodes, int maxIn) {
  default_random_engine gen;
  uniform_int_distribution<int> dis(1, min(numNodes, maxIn));
  vector<Node *> nodeList;
  for (int i = 0; i < numNodes; ++i) {
    nodeList.push_back(new Node(i));
  }
  vector<int> id(nodeList.size());
  iota(id.begin(), id.end(), 0);
  for (int i = 0; i < nodeList.size(); ++i) {
    // always connect with the previous node to make sure
    // the node is reachable from nodeList[0]
    if (i > 0)
      nodeList[i - 1]->neighbors.push_back(nodeList[i]);
    int degree = dis(gen);
    random_shuffle(id.begin(), id.end());
    for (int j = 0; j < degree; ++j) {
      if (id[j] != i && id[j] != i - 1)
        nodeList[id[j]]->neighbors.push_back(nodeList[i]);
    }
  }
  return nodeList[0];
}


int main(int argc, char **argv) {
  Node *graph = gen_graph(atoi(argv[1]), atoi(argv[2]));
  map<Node *, Node *> node_clone;
  set<Node *> node_visited;
  Node *clone = clone_graph(graph, node_clone);
  print_graph(graph, node_visited);
  node_visited.clear();
  cout << endl;
  print_graph(clone, node_visited);
}
