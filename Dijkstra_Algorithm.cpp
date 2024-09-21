#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
class Vertex {
public:
    string label;
    int cost;

    Vertex(string lbl, int cst) : label(lbl), cost(cst) {}
    bool operator>(const Vertex& other) const {
        return cost > other.cost;
    }
};
pair<int, vector<string>> shortestPath(const unordered_map<string, unordered_map<string, int>>& network, const string& source, const string& destination) {
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> queue;
    unordered_map<string, int> minCost;
    unordered_map<string, string> pathTracker;

    for (const auto& node : network) {
        minCost[node.first] = numeric_limits<int>::max();
    }
    minCost[source] = 0;

    queue.push(Vertex(source, 0));

    while (!queue.empty()) {
        Vertex currVertex = queue.top();
        queue.pop();

        if (currVertex.label == destination) {

            vector<string> route;
            string temp = destination;
            while (!pathTracker[temp].empty()) {
                route.insert(route.begin(), temp);
                temp = pathTracker[temp];
            }
            route.insert(route.begin(), source);

            return {minCost[destination], route};
        }

        for (const auto& neighbor : network.at(currVertex.label)) {
            int updatedCost = minCost[currVertex.label] + neighbor.second;
            if (updatedCost < minCost[neighbor.first]) {
                minCost[neighbor.first] = updatedCost;
                pathTracker[neighbor.first] = currVertex.label;
                queue.push(Vertex(neighbor.first, updatedCost));
            }
        }
    }

    return {numeric_limits<int>::max(), {}};
}

int main() {

    unordered_map<string, unordered_map<string, int>> graphMap = {
        {"A", {{"B", 10}, {"E", 3}}},
        {"B", {{"E", 4}, {"C", 2}}},
        {"C", {{"D", 9}}},
        {"D", {{"C", 7}}},
        {"E", {{"B", 1}, {"D", 2}, {"C", 8}}}
    };

    string begin, finish;
    cout << "Enter the starting node: ";
    cin >> begin;
    cout << "Enter the ending node: ";
    cin >> finish;

    auto result = shortestPath(graphMap, begin, finish);

    if (result.first == numeric_limits<int>::max()) {
        cout << "No valid path from " << begin << " to " << finish << "." << endl;
    } else {
        cout << "The cost of the shortest path from " << begin << " to " << finish << " is " << result.first << "." << endl;
        cout << "The shortest path is: ";
        for (const auto& node : result.second) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
