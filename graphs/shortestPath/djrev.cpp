#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;
vector <pair<int,int>> graph[N];
vector <int> dist(N,INF);
vector <bool> vis(N , false);
void dj(int source) {
    set <pair<int,int>> st;
    dist[source] = 0;
    st.insert({0,source});
    
    while (!st.empty()) {

    auto it = *st.begin();
    st.erase(st.begin());

    int dis = it.first;
    int node = it.second;

    for (auto edge : graph[node]) {

        int adjNode = edge.first;
        int wt = edge.second;

        if (dis + wt < dist[adjNode]) {

            if (dist[adjNode] != INF)
                st.erase({dist[adjNode], adjNode});

            dist[adjNode] = dis + wt;
            st.insert({dist[adjNode], adjNode});
        }
    }
}
}
    



int main() {
    int n , m;
    cin>>n>>m;
    
    for (int i = 0 ; i < m ; ++i) {
        int u , v , w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
    
    dj(0);
    
    for (int i = 0; i < n; i++) {
    if (dist[i] == INF)
        cout << "INF ";
    else
        cout << dist[i] << " ";
}
        cout << '\n';
    return 0;
}
