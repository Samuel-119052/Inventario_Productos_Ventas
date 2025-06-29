#include<iostream>
#include<string>
using namespace std;
const int maxp = 100;
const int maxv = 100;
struct Producto {
	string Nompr;
	float Prcp;
};
Producto Pro[maxp];
int Cntpro = 0;
void registrarProducto(){
	if(Cntpro<maxp){
		Producto p;
		cin.ignore();
		cout<<"Nombre del producto: ";
		getline(cin, p.Nompr);
		cout<<"Precio del producto: ";
		cin>>p.Prcp;
		while(p.Prcp<=0){
			cout<<"Numero invalido. Intente de nuevo";
			cin>>p.Prcp;
		}
		Pro[Cntpro] = p;
		Cntpro++;
		cout<<"Producto agregado exitosamente"<<endl;
	}else{
		cout<<"No se puede agregar mas productos. Limite alcanzado"<<endl;
	}
}
void menu(){
	char op;
	while(op!='9'){
		cout<<"Menu"<<endl;
		cout<<"Inventario de productos y ventas"<<endl;
		cout<<"1) Registrar un nuevo producto"<<endl;
		cout<<"Elija una opcion"<<endl;
		cin>>op;
		if(op=='1'){
			registrarProducto();
		}
	}
}
int main(){
	menu();
	return 0;
}