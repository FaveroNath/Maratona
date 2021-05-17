// Exponenciação Binária  - O(long n)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e9 + 7;

ll expBin(ll i, ll n){
	ll ans = 1;

	while(n > 0){
		//Verifica se n é impar
		if(n & 1) ans = ans * i%N;

		i = i * i%N;
		// mesma coisa que dividir por 2
		n >>= 1;
	}
}

int main(){
	ll i, n, ans; cin >> i >> n;
	ans = expBin(i,n);
	cout << ans << endl;
	return 0;
}