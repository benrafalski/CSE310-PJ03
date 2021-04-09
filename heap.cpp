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

int extractMin(HEAP* heap, ptrVertex V) {
	//VERTEX* minV = (VERTEX*)calloc(1, sizeof(VERTEX));
	int min;
	if (heap->size < 1) {
		cout << "Error: heap empty" << endl;
		return 0;
	}
	else {
		min = heap->H[1]->vertex;
		heap->H[1]->vertex = heap->H[heap->size]->vertex;
		//V[heap->H[1]->vertex].pos = 
		heap->H[1]->key = heap->H[heap->size]->key;
		V[heap->H[1]->vertex].pos = V[heap->H[heap->size]->vertex].pos;
		//cout << "extracted pos:" << V[heap->H[1]->vertex].pos << endl;
		heap->size--;

		//cout << "heap called" << endl;
		minHeapify(heap, 1, V);
		//heapifycall++;
		//minV->pos = 0;
		//minV->
		//free(V);
		return min;
	}
}
void insert(HEAP* heap, float key, int value, ptrVertex V) {
	element = (ptrElement)malloc(sizeof(ELEMENT));
	element->vertex = value;
	element->key = key;
	heap->size++;
	heap->H[heap->size] = element;
	//free(element);
	int i = heap->size - 1;
	//heap->H[i]->key = std::numeric_limits<int>::max();
	decreaseKey(heap, i + 1, key, V);
	//printHeap(heap);
}
