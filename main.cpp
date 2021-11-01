/* 
 * 
 * Programación de estructuras de datos y algoritmos fundamentales (TC1031.2)
 * Integral A Avance 1 algoritmos de ordenamiento
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
        //lst.add(line);
        bst.add(line);	
        //v.push_back(line);
		  }
  }

  libro.close();	

}

template <class T>
void vect_to_list(vector<T> &v){				
  for (int i = 0; i < v.size(); i++) {
    lst.update(i,v[i]);
  }
}

//Metodo para ordenar un vetor e ingresar los datos en una lista ya ordenada
template <class T>
void Sort(vector<T> &v){	
  //v = lst.list_to_vect(lst);			
  sorts.ordenaMerge(v);
  vect_to_list(v);
}


int main(int argc, char const *argv[]){
  //lst.list_to_vect(lst);
  vector<string> v;
  string datalist;
  //BST<string> bst;

  leer(v,"libros.txt");

  //lst.list_to_vect(lst);

  int opc;
    
  do{
    cout<<"\n\n-----------Bienvenido-----------\n";
    cout<<"1.- Ver libros (ya ordenados por nombre)\n";
    //cout<<"2.- Ordena libros por titulo\n";
    cout<<"3.- Agregar nuevo libro\n";
    cout<<"4.- Buscar un elemento de tu lista\n";
    cout<<"5.- Eliminar libro\n";
    cout<<"6.- Vaciar biblioteca\n";
    cout<<"7.- Generar reporte\n";
    cout<<"8.- Cerrar";
    cout<<"\n\nIngresa una opción: ";

    cin>>opc;

        switch(opc){
            case 1:
                cout<<bst.visit();
                //lst.display();
                //cout<< lst.count(lst);
            break;

            case 2:
                //v = lst.list_to_vect(lst);
                //Sort(v);
                //lst.display();
            break;

            case 3:
                cout<<"Agrega un libro: \n";
                cin.ignore();
                getline(cin,datalist);
                //lst.add(datalist);
                //lst.list_to_vect(lst);
                //lst.display();

                bst.add(datalist);
                cout<<"¡Libro agregado!";
            break;
            
            case 4:
                cout<<"Verificar libro: \n";
                cin.ignore();
                getline(cin,datalist);
                //cout<<lst.get(datalist)<<"\n";
                //lst.display();
                
                cout<<bst.find(datalist);
            break;
            
            case 5:
                cout<<"Ingresa el libro que quieres eliminar: \n";
                cin.ignore();
                getline(cin,datalist);
                //lst.remove(datalist);
                //lst.display();

                bst.remove(datalist);
            break;
            
            case 6:
                 //lst.clear();
                 bst.removeAll();
            break;

            case 7:
                 ofstream reporte("reporte.txt");
                 if(reporte.is_open()){
                     reporte<<"REPORTE LIBROS \n"<<endl;
                     reporte<<bst.visit()<<endl;
                     reporte.close();
                  cout<<"\nReporte generado con exito\n";
                 }
                 else{
                   cout<<"\nNo se pudo generar reporte\n";
                 }
            break;
        }
    } 
    while(opc != 8);
    cout<<"\nVuelva pronto... Chaito!!!!\n";

    return 0;
}