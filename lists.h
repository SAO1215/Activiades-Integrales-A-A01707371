#ifndef LIST_H_
#define LIST_H_

#include <string>
#include <sstream>
#include "sortmerge.h"

using namespace std;

//Clase Link: Crea los nodos para la clase amiga List
template <class T> class List;

template <class T>
class Link {
private:
    Link(T);
    Link(T, Link<T>*);
    Link(const Link<T>&);

    T        value;
    Link<T> *next;

    friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}

//Clase List: Maneja los metodos para usar listas
template <class T>
class List {
public:
    List();
    List(const List<T>&);
    ~List();

    string toString() const;

    int count(List<T>&);
    void update(int, T);
    void add(T);
    T get(T);
    void remove(T);
    void display();
    void clear();
    vector<T> list_to_vect(List<T>&);

private:
    Link<T> *head;
    int size;
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
    Link<T> *p, *q;
    p = head;

    while (p != 0) {
        q = p->next;
        delete p;
        p = q;
    }
    head = 0;
    size = 0;
}

//Limpia toda la lista
template <class T>
void List<T>::clear() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}

//Metodo count(): Obtiene el numero de nodos de la lista
template <class T>
int List<T>::count(List<T> &lst){
    int count = 0;
    Link<T> *current = head; 

    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

//Metodo update(): Sustituye los valores de la lista
template <class T>
void List<T>::update(int position, T valor){
    int indice;
    Link<T> *p;
    p = head;
    indice = 0;

    while (p != 0) {
		if (indice == position){
            p->value = valor;
            return;
		}
		p = p->next;
		indice++;
	}
}

//Metodo add(): Añade un elemento a la lista
template <class T>
void List<T>::add(T val){
    Link<T> *newL, *p;
    newL = new Link<T>(val);

    if (head == 0) {
        newL->next = head;
        head = newL;
        size++;
        return;
    }
    p = head;
    while (p->next != 0) {
        p = p->next;
    }
    newL->next = 0;
    p->next = newL;
    size++;
}

//Metodo get(): Verifica que un elemento se encuentra en tu lista
template <class T>
T List<T>::get(T val){
    Link<T> *p;
    p = head;

    while (p != 0) {

        if (p->value == val){
            return val;
        }
        p = p->next;
    }
    return "Este elemento no esta en su lista";
}

//Metodo remove(): Elimina un valore de la lista
template <class T>
void List<T>::remove(T val) {
    Link<T> *p, *temp;
    p = head;

    while(p->value != val){
        temp = p;
        p = p->next;
    }
    if(temp == NULL){
        head = head ->next;
        delete p;
    }
    else{
        temp->next = p->next;
        delete p;
    }
}

//Metodo display(): Muestra la lista
template <class T>
void List<T>::display(){
    Link<T> *p;        
    p = head;           
    while(p != NULL){ 
        cout<<p->value<<"\n";
        p = p->next;
    }
}

template <class T>
vector<T> List<T>::list_to_vect(List<T> &lst){
    Link<T> *p;  
    vector<T> v;    
    p = head; 
    int i = 0;
              
    while(p != NULL){ 
        v.push_back(p->value);
        p = p->next;
    }
    /*for (i = 0; i < v.size(); ++i) {
        cout << v.at(i) << "; ";
    }*/
    return v;
}

//Metodo toString(): Muestra la lista
template <class T>
string List<T>::toString() const {
    stringstream aux;
    Link<T> *p;

    p = head;

    while (p != 0) {
        aux << p->value;
        if (p->next != 0) {
            aux << "\n";
        }
        p = p->next;
    }
    return aux.str();
}
#endif