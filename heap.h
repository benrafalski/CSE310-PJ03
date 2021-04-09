typedef struct Element {
	int vertex;
	float key;
}ELEMENT;
typedef ELEMENT* ptrElement;

typedef struct Heap {
	int capacity;
	int size;
	ptrElement* H;
}HEAP;

int parent(int i);
int right(int i);
int left(int i);
int decreaseKey(HEAP* heap, int pos, float newKey, ptrVertex V);
void movingUp(HEAP* heap, int pos);
int extractMin(HEAP* heap, ptrVertex V);
void insert(HEAP* heap, float key, int value, ptrVertex V);
void minHeapify(HEAP* heap, int i, ptrVertex V);
void printHeap(HEAP* H);	
int getPi(int vertex, VERTEX* V);
VERTEX* getGraph(VERTEX* V);
float getWeight(int vertex);
void freeV(VERTEX* V);
void freeE();
