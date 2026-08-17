class DisjointSet {
   private:
    vector<int> rank;

    vector<int> size;

    vector<int> parent;

   public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0 ; i <= n ; i++) {
            parent[i] = i;
        }
    }

    int findUpar(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findUpar(parent[node]);
    }

    bool find(int u, int v) {
        return (findUpar(u) == findUpar(vector));
    }

    void unionByRank(int u, int v) {
        int ult_u = findUpar(u);
        int ult_v = findUpar(v);

        if (ult_u == ult_v) return;

        if (rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v;
        }

        else if (rank[ult_u] > rank[ult_v]) {
            parent[ult_v] = ult_u;
        }

        else {
            parent[ult_u] = ult_v;
            rank[ult_v]++;
        }
    }

    void unionBySize(int u, int v) {
        int ult_u = findUpar(u);
        int ult_v = findUpar(v);

        if (ult_u == ult_v) return;

        if (rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v;
        }

        else if (rank[ult_u] > rank[ult_v]) {
            parent[ult_v] = ult_u;
        }

        else {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
    }
};
