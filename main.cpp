/* 
 * 
 * Programación de estructuras de datos y algoritmos fundamentales (TC1031.2)
 * Integral A
 * Olivia Araceli Morales Quezada
 * A01707371
 *
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "sortmerge.h"
#include "lists.h"
#include "bst.h"

using namespace std;
Sorts<string> sorts;
List<string> lst;
BST<string> bst;

//Menus
void bienvenidaL(){
    cout<<"\n--------Bienvenido--------\n";
    cout<<"1.- Ver libros\n";
    cout<<"2.- Ordena libros por titulo\n";
    cout<<"3.- Agregar nuevo libro\n";
    cout<<"4.- Buscar un elemento de tu lista\n";
    cout<<"5.- Eliminar libro\n";
    cout<<"6.- Generar reporte\n";
    cout<<"7.- Vaciar la biblioteca\n";
    cout<<"8.- Cerrar\n";
    cout<<"Ingresa una opción: ";
}
void bienvenidaA(){
    cout<<"\n-----------Bienvenido-----------\n";
    cout<<"1.- Ver libros (ya ordenados por nombre)\n";
    cout<<"2.- Vaciar biblioteca\n";
    cout<<"3.- Agregar nuevo libro\n";
    cout<<"4.- Buscar un elemento de tu lista\n";
    cout<<"5.- Eliminar libro\n";
    cout<<"6.- Generar reporte\n";
    cout<<"7.- Cerrar";
    cout<<"\n\nIngresa una opción: ";
}

//Metodo para leer el archivo
template <class T>
void leer(vector<T> &v, string doc){
  ifstream libro(doc);
  if(!libro){
    cout<< "No fue posible encontrar el contenido"<<endl;
  }
  string line;
  while(getline(libro, line)){		
      if(line.size() > 0){
        lst.add(line);
        bst.add(line);	
        v.push_back(line);
		  }
  }

  libro.close();	

}

//Metodo para meter el contenido del vector en una lista
template <class T>
void vect_to_list(vector<T> &v){				
  for (int i = 0; i < v.size(); i++) {
    lst.update(i,v[i]);
  }
}

//Metodo para ordenar un vector e ingresar los datos en una lista ya ordenada
template <class T>
void Sort(vector<T> &v){	
  v = lst.list_to_vect(lst);			
  sorts.ordenaMerge(v);
  vect_to_list(v);
}


int main(int argc, char const *argv[]){
  vector<string> v;
  string datalist;
  leer(v,"libros.txt");

  int opc1;
  while(opc1 <= 2) {
        cout<<"*********SELECCION*********";
        cout<<"\n1.- PARA LISTAS";
        cout<<"\n2.- PARA ARBOLES";
        cout<<"\n3.- CERRAR TODO";
        cout<<"\n\nIngresa una opción: ";
        cin >> opc1;   
        switch(opc1){
            case 1:{
                int option2;
                do{
                cout<<"\n\n*********LISTAS*********";
                bienvenidaL();
                cin >> option2;
                switch(option2) {
                    case 1:{
                      lst.display();
                      cout<< "Numero de libros:"<< lst.count(lst);
                    break;}
                    
                    case 2:{
                      Sort(v);
                      lst.display();
                    break;}
                    
                    case 3:{
                      cout<<"Agrega un libro: ";
                      cin.ignore();
                      getline(cin,datalist);
                      lst.add(datalist);
                      cout<<"¡Libro agregado!";
                    break;}
                    
                    case 4:{
                      cout<<"Verificar libro: ";
                      cin.ignore();
                      getline(cin,datalist);
                      cout<<lst.get(datalist)<<"\n";
                    break;}
                    
                    case 5:{
                      cout<<"Ingresa el libro que quieres eliminar: ";
                      cin.ignore();
                      getline(cin,datalist);
                      lst.remove(datalist);
                      cout<<"¡Su libro ha sido eliminado!";
                    break;}
                    
                    case 6:{
                      ofstream reporte("reporte.txt");
                      if(reporte.is_open()){
                        reporte<<"REPORTE LIBROS"<<endl;
                        reporte<<lst.toString()<<endl;
                        reporte.close();
                        cout<<"\nReporte generado con exito\n";}
                      else{
                        cout<<"\nNo se pudo generar reporte\n";}
                        break;}
                    case 7:{
                      lst.clear();
                    break;}
                  } 
                  }while(option2 != 8);
                   cout<<"\nRegresa al menu principal...\n\n";
             }break;
            
            case 2: {
                int option3;
                do{
                cout<<"\n\n*********ARBOLES*********";
                bienvenidaA();

                cin >> option3;
                switch(option3) {
                    case 1:{
                      cout<<bst.visit();
                    break;}
                    
                    case 2:{
                      bst.removeAll();
                    break;}
                    
                    case 3:{
                      cout<<"Agrega un libro: ";
                      cin.ignore();
                      getline(cin,datalist);
                      bst.add(datalist);
                      cout<<"¡Libro agregado!";
                    break;}
                    
                    case 4:{
                      cout<<"Verificar libro: ";
                      cin.ignore();
                      getline(cin,datalist);
                      cout<<bst.find(datalist);
                    break;}
                    
                    case 5:{
                      cout<<"Ingresa el libro que quieres eliminar: ";cin.ignore();
                      getline(cin,datalist);
                      bst.remove(datalist);
                      cout<<"¡Su libro ha sido eliminado!";
                    break;}
                    
                    case 6:{
                      ofstream reporte("reporte.txt");
                      if(reporte.is_open()){
                        reporte<<"REPORTE LIBROS"<<endl;
                        reporte<<bst.visit()<<endl;
                        reporte.close();
                        cout<<"\nReporte generado con exito\n";
                        }
                      else{
                        cout<<"\nNo se pudo generar reporte\n";
                        }
                    break;}
                 }
               
                 }while(option3 != 7);
                 cout<<"\nRegresa al menu principal...\n\n";
             }break;
         }
   }
}
