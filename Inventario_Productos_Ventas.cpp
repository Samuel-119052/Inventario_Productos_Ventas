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
void listaProductos(){
	if(Cntpro==0){
		cout<<"No hay productos registrados"<<endl;
	}else{
		for(int i=0; i<Cntpro; i++){
			Producto pr = Pro[i];
			cout<<"Producto #"<<i+1<<": "<<endl;
			cout<<"Producto: "<<pr.Nompr<<endl;
			cout<<"Precio: "<<pr.Prcp<<"$"<<endl;
		}
	}
}
void buscarProducto(){
	if(Cntpro==0){
		cout<<"No hay productos registrados"<<endl;
	}else{
		cin.ignore();
		string Buspro;
		cout<<"Ingrese el nombre del producto a buscar"<<endl;
		getline(cin, Buspro);
		bool Enc = false;
		for(int i=0; i<Cntpro; i++){
			if(Pro[i].Nompr == Buspro){
				cout<<"Producto encontrado: "<<Pro[i].Nompr<<endl;
				cout<<"Precio: "<<Pro[i].Prcp<<"$"<<endl;
				Enc=true;
			}
		}
		if(Enc==false){
			cout<<"Producto no encontrado"<<endl;
		}
	}
}
void actualizarProducto(){
	if(Cntpro==0){
		cout<<"No hay productos registrados"<<endl;
	}else{
		cin.ignore();
		string Actpro;
		cout<<"Ingrese el nombre del producto a actualizar"<<endl;
		getline(cin, Actpro);
		bool Act=false;
		for(int i=0; i<Cntpro; i++){
			if(Pro[i].Nompr == Actpro){
				cout<<"Nuevo nombre: ";
				getline(cin, Pro[i].Nompr);
				cout<<"Nuevo Precio: ";
				cin>>Pro[i].Prcp;
				cout<<"Producto actualizado"<<endl;
				Act=true;
			}
		}
		if(Act==false){
			cout<<"Producto no encontrado"<<endl;
		}
	}
}
void menu(){
	char op;
	while(op!='9'){
		cout<<"Menu"<<endl;
		cout<<"Inventario de productos y ventas"<<endl;
		cout<<"1) Registrar un nuevo producto"<<endl;
		cout<<"2) Listar Productos"<<endl;
		cout<<"3) Buscar producto"<<endl;
		cout<<"4) Actualizar producto"<<endl;
		cout<<"Elija una opcion"<<endl;
		cin>>op;
		if(op=='1'){
			registrarProducto();
		}else if(op=='2'){
			listaProductos();
		}else if(op=='3'){
			buscarProducto();
		}else if(op=='4'){
			actualizarProducto();
		}
	}
}
int main(){
	menu();
	return 0;
}