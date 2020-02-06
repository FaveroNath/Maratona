#include<bits/stdc++.h>
using namespace std;
bool eh_primo(int n){
  if(n == 1) return false;
  for(int i = 2; i*i <= n; ++i){
    if(n%i == 0) return false;
  }
    return true;
}
int main(){
  int n;
  cin >> n;
  if(eh_primo(n)) cout << "S";
  else cout << "N";
}
