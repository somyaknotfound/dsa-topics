
#define P pair<int,int>

class Solution{
public:
    vector<int> dijkstra(int N, vector<vector<int>> edges, int S) {
        vector <pair<int,int>> g[N];
        vector <int> dist(N , 1e9);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            g[u].push_back({v,w});
            g[v].push_back({u,w});


        }

        priority_queue<P , vector<P> , greater<P>> pq;
        dist[S] = 0;
        pq.push({0 , S});


        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto edge : g[node]) {
                int adjNode = edge.first;
                int wt = edge.second;
                if (wt+dis<dist[adjNode]) {
                    dist[adjNode] = wt+dis;
                    pq.push({dist[adjNode] , adjNode});
                }
            }
        }

        return dist;
    }
};
