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

using namespace std;
Sorts<string> sorts;
List<string> lst;

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
        v.push_back(line);
		  }
  }

  libro.close();	

}

//Metodo para ordenar un vetor e ingresar los datos en una lista ya ordenada
template <class T>
void Sort(vector<T> &v){				
  sorts.ordenaMerge(v);
  for (int i = 0; i < v.size(); i++) {
    lst.update(i,v[i]);
  }
}

int main(int argc, char const *argv[]){
  vector<string> v;
  string datalist;
  leer(v,"libros.txt");
  
  int opc;
    
  do{
    cout<<"\n\n--------Bienvenido--------\n";
    cout<<"1.- Ver libros\n";
    cout<<"2.- Ordena libros por titulo\n";
    cout<<"3.- Agregar nuevo libro\n";
    cout<<"4.- Buscar un elemento de tu lista\n";
    cout<<"5.- Eliminar libro\n";
    cout<<"6.- Generar reporte\n";
    cout<<"7.- Cerrar\n";
    cout<<"Ingresa una opción: ";

    cin>>opc;

        switch(opc){
            case 1:
                lst.display();
                cout<< lst.count(lst);
            break;

            case 2:
                Sort(v);
                lst.display();
            break;

            case 3:
                cout<<"Agrega un libro: \n";
                cin.ignore();
                getline(cin,datalist);
                lst.add(datalist);
              break;
            
            case 4:
                cout<<"Verificar libro: \n";
                cin.ignore();
                getline(cin,datalist);
                cout<<lst.get(datalist)<<"\n";
              break;
            
            case 5:
               cout<<"Ingresa el libro que quieres eliminar: \n";
               cin.ignore();
               getline(cin,datalist);
               lst.remove(datalist);
               break;

            case 6:
                 ofstream reporte("reporte.txt");
                 if(reporte.is_open()){
                     reporte<<lst.toString()<<endl;
                     reporte.close();
                  cout<<"\nReporte generado con exito\n\n";
                 }
                 else{
                   cout<<"\nNo se pudo generar reporte\n\n";
                 }
            break;
        }
    } 
    while(opc != 7);
    cout<<"\nVuelva pronto... Chaito!!!!\n";

    return 0;
}
