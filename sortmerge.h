#ifndef SORTM_H_
#define SORTM_H_

#include <vector>
#include <list>

using namespace std;

//Template de la clase sorts
template < class T >
class Sorts {
  //Funciones de apoyo
  private:
    void copyArray(vector<T>& , vector<T>& , int , int );
    void mergeArray(vector<T>& A, vector<T>& B, int i, int j, int k);
    void mergeSplit(vector<T>& , vector<T>& , int , int );    
    
  public:
    vector<T> ordenaMerge(vector<T>&);
};

//Se usa como mascara para la funcion mergeSplit 
template <class T>
vector<T> Sorts<T>::ordenaMerge(vector<T> &v) {
	vector<T> aux(v.size());

	mergeSplit(v, aux, 0, v.size() - 1);

  return v;
}

//Esta funcion recibe dos vectores, sus indices y usa recursividad para dividirlos
template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high) {
	int mid;

	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}

//Esta funcion combina y ordena los elementos
template <class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high) {

	int i = low;
	int j = mid + 1;
	int k = low;

	while (i <= mid && j <= high) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}

//Esta funcion hace una copia del array
template <class T>
void Sorts<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

#endif