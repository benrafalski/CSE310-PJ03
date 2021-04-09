#include <iostream>
#include <limits>
#include "heap.h"
//#include "graph.h"
using namespace std;
ptrElement element;

int parent(int i) {
	return (i / 2);
}
int right(int i) {
	return ((2 * i) + 1);
}
int left(int i) {
	return (2 * i);
}
int decreaseKey(HEAP* heap, int pos, float newKey, ptrVertex V) {
	//int parent = pos / 2;
	ptrElement temp;
	//cout << pos << endl;
	//cout << heap->size << endl;
	//cout << newKey << endl;
	//cout << heap->H[pos]->key << endl;
	if (pos < 1 || pos > heap->size || newKey > heap->H[pos]->key) {
		//cout << "Error: new key is larger than current key" << endl;
		return 1;
	}
	heap->H[pos]->key = newKey;
	while ((pos > 1) && (heap->H[parent(pos)]->key >= heap->H[pos]->key)) {
		temp = heap->H[pos];
		heap->H[pos] = heap->H[parent(pos)];
		heap->H[parent(pos)] = temp;
		V[heap->H[pos]->vertex].pos = parent(pos);
		V[heap->H[parent(pos)]->vertex].pos = pos;
		pos = parent(pos);
	}
	return 0;
}
void movingUp(HEAP* heap, int pos) {

}
