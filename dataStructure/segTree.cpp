#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, q;
int seg[N+5];
const int NEUTRO = 0;
void update(int no, int l, int r, int pos, int v){
	if(l >= pos && r <= pos){
		seg[no] = v;
		return;
	}
	if(l > pos || r < pos) return;

	int mid = (l+r)>>1;
	update(2*no, l, mid, pos, v);
	update(2*no+1, mid+1, r, pos, v);

	seg[no] = (seg[2*no] + seg[2*no+1]);
	
}

int query(int no, int l, int r, int a, int b){
	if(l >= a && r <= b) return seg[no];
	if(l > b || r < a) return NEUTRO;

	int mid = (l+r)>>1;
	int xL = query(2*no,l, mid, a, b);
	int yR = query(2*no+1, mid+1, r, a, b);

	return (xL+yR);
}

int main(){
	int a, t, x, y; cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a;
		update(1, 1, n, i, a);
	}
	cin >> q;
	while(q--){
		cin >> t >> x >> y;
		if(t == 1) update(1, 1, n, x, y);
		else cout << query(1, 1, n, x, y) << endl;
	}
}
