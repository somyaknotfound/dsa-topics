#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int,int>> g[N];

void dijkstra(int source, int n) {

    vector<int> vis(N, 0);
    vector<int> dist(N, INF);

    set<pair<int,int>> st;

    dist[source] = 0;
    st.insert({0, source});

    while (!st.empty()) {

        auto node = *st.begin();
        st.erase(st.begin());

        int v = node.second;

        if (vis[v]) continue;
        vis[v] = 1;

        for (auto child : g[v]) {

            int child_v = child.first;
            int wt = child.second;

            if (dist[v] + wt < dist[child_v]) {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << '\n';
}

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {

        int x, y, wt;
        cin >> x >> y >> wt;

        g[x].push_back({y, wt});
        // g[y].push_back({x, wt}); // Uncomment if undirected
    }

    int source = 1;
    dijkstra(source, n);

    return 0;
}
