#include <bits/stdc++.h>
using namespace std;

int n; // Number of cities
vector<vector<int>> graph; // The distance matrix
vector<bool> visited; // To keep track of visited cities
int minCost = INT_MAX; // To store the minimum cost

void branchAndBound(int currCost, int level) {
    if (level == n - 1) { // If all cities have been visited
        if (graph[level][0] != 0) { // If there is a path to return to the starting city
            currCost += graph[level][0];
            minCost = min(minCost, currCost);
        }
        return;
    }

    for (int i = 1; i < n; i++) {
        if (!visited[i] && graph[level][i] != 0) {
            visited[i] = true;
            branchAndBound(currCost + graph[level][i], level + 1);
            visited[i] = false;
        }
    }
}

int tspBranchAndBound(vector<vector<int>> &distanceMatrix) {
    n = distanceMatrix.size();
    graph = distanceMatrix;
    visited.resize(n, false);
    visited[0] = true;
    branchAndBound(0, 0);
    return minCost;
}

int main() {
    // Example distance matrix
    vector<vector<int>> distanceMatrix = {
        {0, 29, 20, 21},
        {29, 0, 15, 17},
        {20, 15, 0, 28},
        {21, 17, 28, 0}
    };

    int minTourCost = tspBranchAndBound(distanceMatrix);
    cout << "Minimum TSP cost: " << minTourCost << endl;
    return 0;
}



/*
Minimum TSP cost: 72
*/