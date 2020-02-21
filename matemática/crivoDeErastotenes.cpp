#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int eh_primo[N+5];
typedef long long ll;

void crivo(int n){
    memset(eh_primo, -1, sizeof(eh_primo));
    eh_primo[0] = eh_primo[1] = 0;
    
    for(int i = 2; i <= n; i++){
        if(eh_primo[i] == -1){
            eh_primo[i] = 1;
            cout << i << " ";
            for(int j = 2; i*j <= n; j++){
                eh_primo[i*j] = 0;
            }
        }
    }
}


int main(){
	
	int n; cin >> n;
    	crivo(n);
	return 0;
}
