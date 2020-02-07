#include<bits/stdc++.h>
using namespace std;
const int max = 100010;
int eh_primo[10010000];
vector<int> arr;
void crivo(int n){
	for (int i = 2; i <= n; i++){
		eh_primo[i] = -1;
	}
	for(int i = 2; i <= n; i++){
		if(eh_primo[i] == -1){
			eh_primo[i] = i;
			for (int j = i+i; j <= n; j += i){
				eh_primo[j] = 0;
			}
		}
	}
}
int main(){
	int prim;
	cin >> prim;
	crivo(prim);
	for(int i = 1; i <= prim; i++){
		if(eh_primo[i] != 0) arr.push_back(eh_primo[i]);
	}
	for(int i = 0; i < arr.size(); i++){
	    cout << arr[i] << " ";
	}
}
