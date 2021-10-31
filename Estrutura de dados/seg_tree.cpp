#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6;
ll seg[N+5];

void update(ll node, ll l, ll r, ll pos, ll value) {
	if (l >= pos && pos >= r) { // Totalmente dentro do intervalo
		seg[node] = value;
		return;
	}

	if(l > pos || pos > r) // Fora do intervalo
		return;

	//Parcialmente

	ll mid = (l+r)/2;

	update(2 * node + 1, l, mid, pos, value);
    	update(2 * node + 2, mid + 1, r, pos, value);

	seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
}

ll query(ll node, ll l, ll r, ll left, ll right) {
	if(l >= left && r <= right) // Totalmente dentro do intervalo
		return seg[node];
	
	if(l > right || r < left) // Fora do intervalo
		return 0;

	//Parcialmente

	ll mid = (l+r)/2;

	ll leftNode = query(2 * node + 1, l, mid, left, right);
	ll rightNode = query(2 * node + 2, mid + 1, r, left, right);

	return leftNode + rightNode;
}

int main() {
	ll n, m, a; cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a;
		update(0, 0, n - 1, i, a);
	}

	ll q, i, v; 

	while(m--) {
		cin >> q >> i >> v;

		if(q == 1) 
			update(0, 0, n - 1, i, v);
		else
			cout << query(0, 0, n - 1, i, v-1) << "\n"; 
	}

	return 0;
}