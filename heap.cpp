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
