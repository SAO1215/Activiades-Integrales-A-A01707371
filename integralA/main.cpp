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

using namespace std;

template <class T>
void leer(vector<T> &v, string doc){
  ifstream libro(doc);
  if(!libro){
    cout<< "No fue posible encontrar el contenido"<<endl;
  }
  string line;
  while(getline(libro, line)){		
      if(line.size() > 0){	
        v.push_back(line);
		  }
  }

  libro.close();	

}

template <class T>
void vizualizar(vector<T> &v){
  for(int i = 0; i < v.size(); i++){    
    cout<<v.at(i)<<"\n";
  }
}

int main(int argc, char const *argv[]){
  vector<string> v;
  Sorts<string> sorts;
  leer(v,"libros.txt");
  
  int opc;
    
  do{
    cout<<"\n--------Bienvenido--------\n";
    cout<<"1.- Ver libros\n";
    cout<<"2.- Ordenar libros por titulo\n";
    cout<<"3.- Generar reporte nuevo\n";
    cout<<"4.- Cerrar\n";
    cout<<"Ingresa una opción: ";

    cin>>opc;

        switch(opc){
            case 1:
                vizualizar(v);
            break;

            case 2: 
                sorts.ordenaMerge(v);
                vizualizar(v);
            break;

            case 3:
                 ofstream reporte("reporte.txt");
                 if(reporte.is_open()){
                   for(string & line: v){
                     reporte<<line<<endl;
                     }
                     reporte.close();
                  cout<<"\nReporte generado con exito\n\n";
                 }
                 else{
                   cout<<"\nNo se pudo generar reporte\n\n";
                 }
            break;
        }
    } 
    while(opc != 4);
    cout<<"\nVuelva pronto... Chaito!!!!\n";

    return 0;
}