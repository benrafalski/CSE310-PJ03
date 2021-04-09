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
void minHeapify(HEAP* heap, int i, ptrVertex V) {
	int l = left(i);
	int r = right(i);
	//cout << l+1 << ", " << r+1 << endl;
	int smallest, temp;
	if ((l <= heap->size) && (heap->H[l]->key < heap->H[i]->key)) {
		smallest = l;
		//cout << "smallest = " << smallest+1 << endl;
	}
	else {
		smallest = i;
		//cout << "smallest = " << smallest+1 << endl;
	}
	if ((r <= heap->size) && (heap->H[r]->key < heap->H[smallest]->key)) {
		smallest = r;
		//cout << "smallest = " << smallest+1 << endl;
	}
	if (smallest != i) {
		temp = heap->H[i]->key;
		heap->H[i]->key = heap->H[smallest]->key;
		heap->H[smallest]->key = temp;
		V[heap->H[i]->vertex].pos = smallest;
		V[heap->H[smallest]->vertex].pos = i;
		minHeapify(heap, smallest, V);
		//cout << "if heapify call" << endl;
		//heapifycall++;
	}
	//cout << endl;
}
void printHeap(HEAP* H) {
	// prints capacity and size of heap to stdout
	cout << "capacity=" << H->capacity << ", size=" << H->size << endl;
	for (int i = 1; i <= H->size; i++) {
		if (i == (H->size)) {
			// prints each key value of heap
			cout << "key[" << H->H[i]->vertex << "]= " << H->H[i]->key << endl;
		}
		else {
			// prints last key value in heap
			cout << "key[" << H->H[i]->vertex << "]= " << H->H[i]->key << ", " << endl;
		}
	}
}
int getPi(int vertex, VERTEX* V) {
	return V[vertex].pi;
}
VERTEX* getGraph(VERTEX* V) {
	return V;
}
void freeV(VERTEX* V) {
	free(V);
}
void freeE() {
	free(element);
}
