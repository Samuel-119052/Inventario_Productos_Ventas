#include<iostream>
#include<string>
using namespace std;
const int maxp = 100;
const int maxv = 100;
struct Producto {
	string Nompr;
	float Prcp;
};
struct Venta {
	int Idvnt;
	string Pdct;
	int Cnt;
	float Prct;
};
Producto Pro[maxp];
Venta Vnt[maxv];
int Cntpro = 0;
int Cntvnt = 0;
int Contv = 1;
void totalVentas(){
	float Ttl=0;
	for(int i=0; i<Cntvnt; i++){
		Ttl += Vnt[i].Prct;
	}
	cout<<"Total de todas las ventas: $"<<Ttl<<endl;
}
void listaVentas(){
	if(Cntvnt==0){
		cout<<"No hay ventas registradas"<<endl;
	}else{
		for(int i=0; i<Cntvnt; i++){
			cout<<"Id Producto: "<<Vnt[i].Idvnt<<endl;
			cout<<"Producto: "<<Vnt[i].Pdct<<endl;
			cout<<"Cantidad: "<<Vnt[i].Cnt<<endl;
			cout<<"Total: $"<<Vnt[i].Prct<<endl;
		}
	}
}
void registrarVenta(){
	if(Cntvnt < maxv){
		cin.ignore();
		string Nompro;
		int Cnt;
		bool Rgt = false;
		cout<<"Nombre del producto vendido: ";
		getline(cin, Nompro);
		cout<<"Cantidad vendida: ";
		cin>>Cnt;
		while(Cnt<=0){
			cout<<"Intentelo denuevo"<<endl;
			cin>>Cnt;
		}
		for(int i=0; i<Cntpro; i++){
			if(Pro[i].Nompr == Nompro){
				Vnt[i].Idvnt = Contv++;
				Vnt[i].Pdct = Nompro;
				Vnt[i].Cnt = Cnt;
				Vnt[i].Prct = Pro[i].Prcp * Cnt;
				Cntvnt++;
				cout<<"Venta registrada. Total: $ "<< Pro[i].Prcp * Cnt<<endl;
				Rgt = true;
			}
		}
		if(Rgt == false){
			cout<<"Producto no encontrado"<<endl;
		}
	}else{
		cout<<"Limite de ventas alcanzado"<<endl;
	}	
}
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
void eliminarProducto(){
	if(Cntpro==0){
		cout<<"No hay productos registrados"<<endl;
	}else{
		string Probus;
		cout<<"Ingrese el producto a eliminar"<<endl;
		cin.ignore();
		getline(cin, Probus);
		int Proeli = -1;
		for(int i=0; i<Cntpro; i++){
			if(Pro[i].Nompr==Probus){
				Proeli=i;
			}
		}
		if(Proeli!=-1){
			for(int j=Proeli; j<Cntpro-1; j++){
				Pro[j]=Pro[j+1];
			}
			Cntpro--;
			cout<<"Producto eliminado"<<endl;
		}else{
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
		cout<<"5) Eliminar producto"<<endl;
		cout<<"6) Registra una venta"<<endl;
		cout<<"7) Listar ventas"<<endl;
		cout<<"8) Total de ventas"<<endl;
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
		}else if(op=='5'){
			eliminarProducto();
		}else if(op=='6'){
			registrarVenta();
		}else if(op=='7'){
			listaVentas();
		}else if(op=='8'){
			totalVentas();
		}
	}
}
int main(){
	menu();
	return 0;
}