#include <bits/stdc++.h>
using namespace std;

void dfs(int vertex,
         int parent,
         vector<vector<int>>& g,
         vector<int>& subtreeSum,
         vector<int>& evenCount) {

    // Base contribution from the current node
    subtreeSum[vertex] = vertex;          // Assuming node value = node number
    evenCount[vertex] = (vertex % 2 == 0);

    for (int child : g[vertex]) {
        if (child == parent) continue;

        dfs(child, vertex, g, subtreeSum, evenCount);

        // Use the values already computed for the child
      // essential for calling multiple dp here itself
      
        subtreeSum[vertex] += subtreeSum[child];
        evenCount[vertex] += evenCount[child];
    }
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> subtreeSum(n + 1);
    vector<int> evenCount(n + 1);

    dfs(1, 0, g, subtreeSum, evenCount);

    int q;
    cin >> q;

    while (q--) {
        int v;
        cin >> v;

        cout << "Subtree Sum = " << subtreeSum[v] << '\n';
        cout << "Even Count = " << evenCount[v] << '\n';
    }

    return 0;
}
