#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int NEUTRO = 1;
int seg[4*N];

void update(int no, int left, int right, int pos, int valor)
{
	if(left >= pos && right <= pos) // Estou inteiramente no intervalo?
	{
		seg[no] = valor;
		return;
	}
	if(left > pos || right < pos) //Estou Fora?
	{
		return;
	}

	//Parcialmente
	int meio = (left + right)>>1;
	update(2*no, left, meio, pos, valor); //Filho Esquerda
	update(2*no+1, meio+1, right, pos, valor); // Filho Direita

	seg[no] = (seg[2*no] * seg[2*no+1]);
}
int query(int no, int left, int right, int a, int b)
{
	if(left >= a && right <= b)
	{
		return seg[no]; //**** Corrigir Depois
	}
	if(left > b || right < a)
	{
		return NEUTRO;
	}

	int meio = (left + right)>>1;
	int vLeft = query(2*no, left, meio, a, b);
	int vRight = query(2*no+1, meio+1, right, a, b);

	return (vLeft*vRight);
}
int main()
{
	while(true)
	{
		try
		{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) // Preencher a Tree, começando do primeiro no
		{
			int elem;
			cin >> elem;
			update(1, 1, n, i, elem);
		}
		while(k--)
		{
			string op = "";
			cin >> op;
			if(op == "C")
			{
				int pos, valor;
				cin >> pos >> valor;
				update(1, 1, n, pos, valor);
			}
			else if(op == "P")
			{
				int a, b;
				cin >> a >> b;
				if((query(1, 1, n, a, b)) > 0)
				{
					cout << "+" ;
				}
				else if((query(1, 1, n, a, b)) < 0)
				{
					cout << "-";
				}
				else
				{
					cout << 0;
				}
			}
			if(k == 0)
			{
				cout << endl;
			}
		}
		}
		catch (int x)
		{
			break;
		}
	}
	return 0;
}