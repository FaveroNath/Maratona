#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int N = 1e6;
ll n, m, fact = 0;
int prime[N+5];
vector<ll> primes;

void sieve(){
   memset(prime, -1, sizeof(prime));
   prime[0] = prime[1] = 0;
   for(ll i = 2; i <= N; i++){
       if(prime[i] == -1){
           prime[i] = 1;
           primes.push_back(i);
           fact++;
           for(ll j = 2; i*j <= N; j++){
               prime[i*j] = 0;
           }
       }
   }
}
ll get_power(int n, int p){
    ll ans = 0;
    while(n){
        n/= p;
        ans += n;
    }
    return ans;
}

bool factovisors(int n, int m){
    for(ll i = 0; i < fact && primes[i]*primes[i] <= m; i++){
        if(m%primes[i] == 0){
            int cnt = 0;
            while(m%primes[i] == 0)
                cnt++, m /= primes[i];
                ll tmp = primes[i], cnt2 = 0;
                while(tmp <= n) {
                    cnt2 += n/tmp;
                    tmp *= primes[i];
                }
                if(cnt2 < cnt) return 0;
        }
    }
    if(m != 1){
        if(n < m) return 0;
    }
    return 1;
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
        while(cin >> n >> m){
        if(factovisors(n,m)){
            cout << m << " divides " << n << "!" << endl;
        }
        else{
            cout << m << " does not divide " << n << "!" << endl;
        }
    }
    return 0;
}
