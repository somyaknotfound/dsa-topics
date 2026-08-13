#include <bits/stdc++.h>
using namespace std;

const int N = 510;
const int INF = 1e9 + 10;

int dist[N][N];

int main() {
    // 1. Initialize distance matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; ++j) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    int n, m;
    cin >> n >> m;

    // 2. Read graph edges
    for (int i = 0; i < m; ++i) {
        int x, y, wt;
        cin >> x >> y >> wt;
        dist[x][y] = wt; // For directed graph (add dist[y][x] = wt if undirected)
    }

    // 3. Floyd-Warshall Algorithm
    // 'k' MUST be the outermost loop
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // 4. Output results (optional example print)
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == INF) cout << "I ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
