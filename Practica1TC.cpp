#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> indexCreation(vector<string> match){
	int m = match.size();
	vector<int> arr(m);
	arr[0] = 0;
	int i =1,j=0;
	while(i < m){
		if(match[i] == match[j]){
			j++;
			arr[i] = j;
			i++;
		}

		if(match[i] != match[j] && j == 0){
			arr[i] = j;
			i++;
		}

		if(match[i] != match[j] && j != 0){
			j = arr[j-1];
		}
	}
	return arr;
} 

void KMP(vector<string> texto, vector<string> buscar){
	int M = buscar.size();
	int N = texto.size();
	vector <int> indices;
	indices = indexCreation(buscar);
	bool check = true;
	int i=0,j=0;
	while(i < N && j < M){
		if(buscar[j] == texto[i]){
			j++;
			i++;
		}
		else{
			if(i < N && buscar[j] != texto[i]){
				if(j != 0){
					j = indices[j-1];
				}
				else{
					i++;
				}
			}
		}

		if(j == M){
			check = false;
			cout << "Patter found at index " << (i-j) + 1 << "\n";
			if((i - j) == 0){
				cout << "Es un prefijo\n";
			}
			else{
				if((i-j) + M == N){
					cout << "Es un sufijo\n";
				}
				else{
					cout << "Es una subcadena\n";
				}
			}
			j = indices[j-1]; 
		}
		
	}
	if (check)
	{
		cout << "W1 no se encuentra en W2" <<endl;
	}
	return ;
}

void ingresoAlfabeto(vector<string> *alfabeto1,unordered_map<string,bool> *umap){
	bool b,flag=false;
	int opc,as1,as2;
	string a,aux;
	char r1,r2;
	

	do{	
		cout << "\n1.-Introducir alfabeto por caracteres individuales\n";
		cout << "2.-Introducir alfabeto por rango de caracteres \n";
		cin >> opc;
		if(opc == 1){
			cout << "Introduce los caracteres: \n";
			while(true){
				cin >> a;
				if(a == "&"){
					break;
				}
				else{
					if((*umap).count(a) != 0){
						flag = true;
					}
					else{
						(*alfabeto1).push_back(a);
						(*umap)[a] = true;
					}
				}
			}
			if (flag)
			{	
				cout << "\nNo se pueden repetir caracteres en un alfabeto \n";
				(*alfabeto1).clear();
				(*umap).clear();
				opc = 3;
				//ingresoAlfabeto(alfabeto1,umap);
			}
		}
		else if(opc == 2){
			cout << "Introduzca el rango de caracteres (inicial final)\n";
			cin >> r1 >> r2;
			as1 = (int)r1;
			as2 = (int) r2;
			//cout << as1 << as2 << endl;
			for (int i = as1; i <= as2; ++i)
			{
				aux = (char)i;
				//cout << aux << endl;
				(*alfabeto1).push_back(aux);
			}
		}
	}while(opc != 1 && opc != 2);
	
	
	return ;
}

void potencia(vector<string> w1,vector<string> w2){
	int p;
	cout << "Introduce la potencia: \n";
	cin >> p;
	for (int i = 0; i < p; ++i)
	{
		for (int j = 0; j < w1.size(); ++j)
		{
			cout << w1[j];
		}
		for (int k = 0; k < w2.size(); ++k)
		{
			cout << w2[k];
		}
	} cout << "\n";
	return ;
}

void timesString(vector<string> word){
	int count=0;
	string s;
	cout << "Simbolo a buscar \n";
	cin >> s;
	for (int i = 0; i < word.size(); ++i)
	{
		if(word[i] == s){
			count++;
		}
	}
	cout << "Palabra: ";
	for (int i = 0; i < word.size(); ++i)
	{
		cout << word[i];
	}
	cout << "\n";
	cout << "Se repite " << count << " veces \n";
	return ;
}

bool check(vector<string> alpha,vector<string> p,  unordered_map<string,bool> umap){
	

	int i =0;
	bool flag = true;
	for (int j = 0; j < p.size();++j)
	{
		// si la llave no existe
		if (umap.count(p[j]) == 0) 
		//if(umap.find(p[j]) == umap.end())
		{
			cout << p[j] << " ";
			cout << "Error: La cadena es incorrecta"<< "\n";
			flag = false;
			break;
		}
	}

	return flag;
}

vector<string> pedirString(vector<string> alpha,  unordered_map<string,bool> umap){
	bool b = true;
	vector<string> p;
	string a;
	cout << "Introduce la cadena: " << endl;
	do{	
		if(!b){
			p.clear();
		}
		while(true){
			cin >> a;
			if(a == "&"){
				break;
			}
			else{
				p.push_back(a);
			}
		}
		b = check(alpha,p,umap);
	}while(!b);
	return p;
}

void printElements(vector<string> v){
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << "\n";
	return ;
}

vector<string> multiABC(vector<string> alpha, vector<string> beta){
	string aux;
	vector <string> r;
	
	for (int i = 0; i < alpha.size(); ++i)
	{
		for (int j = 0; j < beta.size(); ++j)
		{
			aux = alpha[i] + beta[j];
			r.push_back(aux);
		}
	}
	
	return r;
}

void powerOne(vector<string> alpha){
	for (int i = 0; i < alpha.size(); ++i)
	{
		cout << alpha[i] << "\n";
	}
}

void powerABC(vector<string> alpha, string past, int pow,bool check){
	if(check){
		for (int i = 0; i < alpha.size(); ++i)
		{
			powerABC(alpha,alpha[i],pow-1,false);
		}
	}
	else{
		if(pow > 1){
			for (int i = 0; i < alpha.size(); ++i)
			{
				powerABC(alpha,past+alpha[i],pow-1,false);
			}
		}
		else{
			for (int i = 0; i < alpha.size(); ++i)
			{
				cout << past + alpha[i] << " ";
			}
			cout << "\n";
		}		
	}
	return ;
}

//Checar esta funcion

void filterPow(vector<string> alpha,int poten){
	vector<string> aux;
	string ayuda;
	int a=0, i=1;
	if(poten < 0){
		while((i-1)< alpha.size()){
			ayuda = alpha[alpha.size()-i];
			aux.push_back(ayuda);
			i++;
		}
		if(abs(poten) == 1)
			powerOne(aux);
		else
			powerABC(aux," ",abs(poten),true);
	}
	else{
		if(poten == 1)
			powerOne(alpha);
		else
			powerABC(alpha," ",poten,true);
	}
}

int main(){
	vector<string> alfabeto1,alfabeto2;
	vector<string> p1,p2;
	int opc,pot,times;
	vector <string> resultado;
	unordered_map<string,bool> umap,umap2;
	vector<string> mandar;
	
	cout << "Ingresa el alfabeto 1: \n";
	//inciso a
	ingresoAlfabeto(&alfabeto1,&umap);
	cout << "Ingresa el alfabeto 2: \n";
	//inciso b
	ingresoAlfabeto(&alfabeto2,&umap2); 

	do{
		cout << "MENU\n"
		<<	"1.-Ingresa las cadenas del ABC1\n"
		<<	"2.-Generar la potencia de las cadenas\n"
		<<	"3.-Encontrar un simbolo en una cadena\n"
		<<	"4.-Saber si w1 es subcadena de w2\n"
		<<	"5.-Sacar la potencia de un alfabeto\n"
		<<	"6.-Multiplicar ABC1 * ABC2\n"
		<<	"7.-Multiplicar ABC1 * ABC2 * ABC1 \n"
		<<	"8.- Terminar\n";
		cin >> opc;
		switch(opc){
			case 1:{
				//inciso c
				p1=pedirString(alfabeto1,umap);
				p2 = pedirString(alfabeto1,umap);
				break;
			}
			case 2:{
				//inciso d
				potencia(p1,p2);
				break;
			}
			case 3:{
				//inciso
				do{
					cout << "Usar cadena 1 o cadena 2: "<<endl;
					cin >> times;
					if (times == 1){
						timesString(p1);
					}
					else if(times == 2){
						timesString(p2);
					}
				}while(times != 1 || times != 2);
				break;
			}
			case 4:{
				//indexCreation(mandar);
				if(p1.size() !=0){
					KMP(p2,p1);
				}
				else
					cout << "Error\n";
				break;
			}
			case 5:{
				//inciso
				cout << "Introduce la potencia deseada: \n";
				cin >> pot;
				filterPow(alfabeto1,pot);
				cout << "\n";
				break;
			}
			case 6:{
				//incisos h e i 
				cout << "Resultado: \n";
				resultado = multiABC(alfabeto1,alfabeto2);
				cout << "\n";
				printElements(resultado);
				resultado.clear();
				break;
			}
			case 7:{
				cout << "Resultado: \n";
				resultado = multiABC(multiABC(alfabeto1,alfabeto2),alfabeto1);
				cout << "\n";
				printElements(resultado);
				resultado.clear();
				break;
			}
		}
	}while(opc > 0 && opc < 8);
	cout << "Goodbye rey";
	return 0;
}