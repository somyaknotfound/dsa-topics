#define P pair<int,int>
class Solution{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
       priority_queue<P , vector<P> , greater<P>> pq;
       vector <int> vis(V , 0);
       pq.push({0,0});
       int sum = 0 ;

       while (!pq.empty()) {
        auto p = pq.top();
        int node = p.second;
        pq.pop();
        int wt = p.first;
        if (vis[node] == 1) continue;
        vis[node] = 1;
        sum+=wt;
        for (auto it : adj[node]) {
            int edgeWt = it[1];
            int adjNode = it[0];

            if (vis[adjNode] == 0) {
                pq.push({edgeWt , adjNode});
            }
        }
       }

       return sum;
    }
};
