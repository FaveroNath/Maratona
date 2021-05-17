#include<bits/stdc++.h>
using namespace std;
char car[] = {'+','-','*','/','%'};
bool buscaCar(char x){
	for(int i = 0; i < 5; i++){
		if(x == car[i]) return true;
	}
	return false;
}
bool procErro(string s){
	int len = s.size(), cont = 0, contOp = 0;
	for(int i = 0; i < len; i++){
		if(s[i] == '('){
			cont++;
		}
		else if(s[i] == ')'){
			cont--;
			if(cont < 0)break;
		}
		cout << buscaCar(s[i]) << " ";
		if(((buscaCar(s[i]) == 1) && (s[i+1] == ' ')) || ((buscaCar(s[i]) == 1) && (s[i-1] == ' '))){
			contOp++;
			//cout << contOp << endl;
			break;
		}
		
	}
	if(cont != 0 || contOp != 0){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	string s;
	getline(cin,s);
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	// Função que eleimina espaço -eEsp()-
	// Função que procura erro -procErro()-
	// Função que procura se é -impróprio()-
	if(procErro(s)){
		cout << "error" << endl;	
	}
	else{
		/*if(procImp(s)){
			cout << "improper";
		}
		else{
			cout << "proper";
		}*/
	}	
}
/*
- Casos que dão erro
abri paresteses com nada dentro
uma operação e nada antes ou depois

*/
