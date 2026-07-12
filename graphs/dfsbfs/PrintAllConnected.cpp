#include <bits/stdc++.h>
using namespace std;


const int N = 1e5+10;

vector <int> g[N];
bool vis[N];
int cnt = 0;
void dfs(int v , vector <int> &vec){

    // cout<<"Enter "<<v<<endl;

    vis[v]=true;
    vec.push_back(v);

    for(int child:g[v]){
        
        if (vis[child]) continue;

        // cout<<"Going "<<v<<" -> "<<child<<endl;

        dfs(child , vec);

        // cout<<"Back "<<child<<" -> "<<v<<endl;
    }

    // cout<<"Exit "<<v<<endl;
}

int main() {

	int n, m;
	cin>>n>>m;

	for (int i = 0 ; i < m ; ++i) {
		int v1, v2;
		cin>> v1 >>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	
	vector <vector <int>> connected_all;
	vector <int> currentConnected;
	
	for (int i = 1 ; i<= n ; i++) {
	    if (!vis[i]) {
	        currentConnected.clear();
	        dfs(i , currentConnected);
	        connected_all.push_back(currentConnected);
	    }
	}
	
	for (auto connectedVector : connected_all) {
	    for (auto component : connectedVector) {
	        cout << component << " ";
	    }
	    cout << endl;
	}
	
	
	
    
    
    
	return 0;
}




