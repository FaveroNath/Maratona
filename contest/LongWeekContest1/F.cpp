#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second	
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
const int N = 1e3, INF = 0x3f3f3f3f;
char g[N+5][N+5];
int n, m, t;
int dist[N+5][N+5];

int dijkstra(int r, int c, int c1, int r1){
	memset(dist, INF, sizeof(dist));
	dist[r][c] = 0;
	priority_queue<iii, vector<iii>, greater<iii> > heap;
	heap.push(iii(0, ii(r,c)));
	while(!heap.empty()){
		int d = heap.top().F, i = heap.top().S.F, j = heap.top().S.S;
		heap.pop();
		if(d > dist[i][j]) continue;
		if(i-1 > 0 && j-1 > 0){
			if(g[i][j] ==  '7' ){
				if( dist[i][j] < dist[i-1][j-1]){
					dist[i-1][j-1]= dist[i][j];
					heap.push(iii(dist[i-1][j-1], ii(i-1,j-1)));
				}
			}else{
				if( dist[i][j]+1 < dist[i-1][j-1]){
					dist[i-1][j-1]= dist[i][j]+1;
					heap.push(iii(dist[i-1][j-1], ii(i-1,j-1)));	
				}
			}
		}
		if(i-1 > 0){
			if(g[i][j] ==  '0' ){
				if( dist[i][j] < dist[i-1][j]){
					dist[i-1][j]= dist[i][j];
					heap.push(iii(dist[i-1][j], ii(i-1,j)));
				}
			}else{
				if( dist[i][j]+1 < dist[i-1][j]){
					dist[i-1][j]= dist[i][j]+1;
					heap.push(iii(dist[i-1][j], ii(i-1,j)));	
				}
			}
		}
		if(i-1 > 0 && j+1 <= m){
			if(g[i][j] ==  '1' ){
				if( dist[i][j] < dist[i-1][j+1]){
					dist[i-1][j+1]= dist[i][j];
					heap.push(iii(dist[i-1][j+1], ii(i-1,j+1)));
				}
			}else{
				if( dist[i][j]+1 < dist[i-1][j+1]){
					dist[i-1][j+1]= dist[i][j]+1;
					heap.push(iii(dist[i-1][j+1], ii(i-1,j+1)));	
				}
			}
		}
		if(j+1 <= m){
			if(g[i][j] ==  '2' ){
				if( dist[i][j] < dist[i][j+1]){
					dist[i][j+1]= dist[i][j];
					heap.push(iii(dist[i][j+1], ii(i,j+1)));
				}
			}else{
				if( dist[i][j]+1 < dist[i][j+1]){
					dist[i][j+1]= dist[i][j]+1;
					heap.push(iii(dist[i][j+1], ii(i,j+1)));	
				}
			}
		}
		if(i+1 <= n && j+1 <= m){
			if(g[i][j] ==  '3' ){
				if( dist[i][j] < dist[i+1][j+1]){
					dist[i+1][j+1]= dist[i][j];
					heap.push(iii(dist[i+1][j+1], ii(i+1,j+1)));
				}
			}else{
				if( dist[i][j]+1 < dist[i+1][j+1]){
					dist[i+1][j+1]= dist[i][j]+1;
					heap.push(iii(dist[i+1][j+1], ii(i+1,j+1)));	
				}
			}
		}
		if(i+1 <= n){
			if(g[i][j] ==  '4' ){
				if( dist[i][j] < dist[i+1][j]){
					dist[i+1][j]= dist[i][j];
					heap.push(iii(dist[i+1][j], ii(i+1,j)));
				}
			}else{
				if( dist[i][j]+1 < dist[i+1][j]){
					dist[i+1][j]= dist[i][j]+1;
					heap.push(iii(dist[i+1][j], ii(i+1,j)));	
				}
			}
		}
		if(i+1 <= n && j-1 > 0){
			if(g[i][j] ==  '5' ){
				if( dist[i][j] < dist[i+1][j-1]){
					dist[i+1][j-1]= dist[i][j];
					heap.push(iii(dist[i+1][j-1], ii(i+1,j-1)));
				}
			}else{
				if( dist[i][j]+1 < dist[i+1][j-1]){
					dist[i+1][j-1]= dist[i][j]+1;
					heap.push(iii(dist[i+1][j-1], ii(i+1,j-1)));	
				}
			}
		}
		if(j-1 > 0){
			if(g[i][j] ==  '6' ){
				if( dist[i][j] < dist[i][j-1]){
					dist[i][j-1]= dist[i][j];
					heap.push(iii(dist[i][j-1], ii(i,j-1)));
				}
			}else{
				if( dist[i][j]+1 < dist[i][j-1]){
					dist[i][j-1]= dist[i][j]+1;
					heap.push(iii(dist[i][j-1], ii(i,j-1)));	
				}
			}
		}
	}
	return dist[c1][r1];
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)cin >> g[i][j];
	}
	cin >> t;
	while(t--){
		int r, c, r1, c1;
		cin >> r >> c >> r1 >> c1;
		cout << dijkstra(r, c, r1, c1) << endl;
	}
}
