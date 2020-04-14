#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
map<string, int> mp;
int n,m, comp = 0, ans = 0 ;
vector<int> g[N+5];
int  vis[N+5];

void DFS(int pos){
	vis[pos] = 1;
	comp++;
	for(int i = 0; i < g[pos].size(); i++){
		int ne = g[pos][i];
		if(!vis[ne]){
	        ans = max(ans, comp);
	        DFS(ne);
		}
	}
}

int main(){
	string c, x, y;
	while(true){
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		for(int i = 1; i <= n; i++){
			cin >> c;
			mp.insert(make_pair(c,i));
			//g[i].push_back(0);
		}
		for(int i = 1; i <= m; i++){
			cin >> x >> y;
			g[mp[x]].push_back(mp[y]);
			g[mp[y]].push_back(mp[x]);
		}
		for(int i = 1; i <= n; i++){
			DFS(i);
			comp = 0;
		}
		cout << ans+1 << endl;
		ans = 0;
		memset(vis, 0, sizeof(vis)); memset(g, 0, sizeof(g));
		
	}
}
