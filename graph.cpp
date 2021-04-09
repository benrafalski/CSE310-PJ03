#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>
#include "graph.h"
#include "heap.h"
using namespace std;


VERTEX* V = NULL;
int countPath = 0;
//int* a = new int[100];
int a[100];
int computed[100];
int compCount = 0;
int dijkstra(int n, ptrNode* A, int s, int t, int flag) {
	//VERTEX* V;
	ptrNode node = NULL;
	//VERTEX* u;
	V = (VERTEX*)calloc(n + 1, sizeof(VERTEX));
	//u = (VERTEX*)calloc(1, sizeof(VERTEX));
	for (int i = 1; i <= n; i++) {
		V[i].color = white;
		V[i].dist = std::numeric_limits<float>::max();
		V[i].pi = 0;
		V[i].pos = 0;
	}
	V[s].dist = 0;
	V[s].color = gray;
	//initialize heap
	HEAP* heap = (HEAP*)calloc(1, sizeof(HEAP));
	heap->capacity = n;
	//cout << heap->capacity << endl;
	heap->size = 0;
	heap->H = (ptrElement*)calloc(n + 1, sizeof(ptrElement));
	heap->H[0] = (ptrElement)malloc(sizeof(ELEMENT));
	heap->H[0]->key = 1000;
	heap->H[0]->vertex = 1000;
	insert(heap, V[s].dist, s, V);
	if (flag == 1) {
		//cout << "Inserted vertex " << s << ", key=" << V[s].dist << endl;
		printf("Insert vertex %d, key=%12.4f\n", s, V[s].dist);
		//freeE();
		//printHeap(heap);
		computed[compCount] = s;
		//cout << computed[compCount] << endl;
		compCount++;
	}
	while (heap->size != 0) {
		int u = extractMin(heap, V);
		if (flag == 1) {
			//cout.precision(4);
			//cout << "Deleted vertex " << u << ", key=" << setw(12) <<  V[u].dist << endl;
			printf("Delete vertex %d, key=%12.4f\n", u, V[u].dist);
		}
		//cout << "size:" << heap->size << endl;
		//cout << "u:" << u <<",pos = " << V[u].pos<<  endl;
		V[u].color = black;
		if (u == t) {
			//free(heap->H[0]);
			//free(heap->H);
			//free(heap->H[0]);
			free(heap);
			//free(heap->H);
			//free(heap->H[0]);
			//freeE();
			return 0;
		}
		node = A[u];
		//cout << node->v << endl;
		while (node) {
			if (V[node->v].color == white) {
				//cout << "node " << node->v << "=" << white << endl;
				V[node->v].dist = V[u].dist + node->w;
				V[node->v].pi = u;
				V[node->v].color = gray;
				//insert v into Q
				//cout << "v1:" << node->v << endl;
				insert(heap, V[node->v].dist, node->v, V);
				if (flag == 1) {
					//cout << "Inserted vertex " << node->v << ", key=" << V[node->v].dist << endl;
					printf("Insert vertex %d, key=%12.4f\n", node->v, V[node->v].dist);
					computed[compCount] = node->v;
					//cout << computed[compCount] << endl;
					compCount++;
				}
			}
			//			/*
			else if (V[node->v].dist > (V[u].dist + node->w)) {
				float oldDist = V[node->v].dist;
				V[node->v].dist = V[u].dist + node->w;
				V[node->v].pi = u;
				//cout << "v2:" << node->v << "," << V[node->v].pos << "," << V[node->v].dist << endl;
				decreaseKey(heap, V[node->v].pos, V[node->v].dist, V);
				if (flag == 1) {
					printf("Decrease key of vertex %d, from %12.4f to %12.4f\n", node->v, oldDist, V[node->v].dist);
					//cout << "Decrease key of vertex " << node->v << ", from " << oldDist << " to " << V[node->v].dist << endl;
				}
			}
			//			*/
			node = node->next;
			//printHeap(heap);

			/*
			for (int i = 1; i <= n; i++) {
				cout << "vertex " << i << ":" << endl;

				cout << V[i].color << "," << V[i].dist << "," << V[i].pi << "," << V[i].pos << endl;

			}
			*/
		}

	}
	//printHeap(heap);
	/*
	for (int i = 1; i <= n; i++) {
		cout << "vertex " << i << ":" << endl;

		cout << V[i].color << "," << V[i].dist << "," << V[i].pi << "," << V[i].pos << endl;

	}
	*/
	//free(heap->H[0]);
	//free(heap->H);
	//free(heap->H[0]);
	//free(node);
	free(heap);
	//free(heap->H);
	//free(heap->H[0]);
	//freeE();
	return 1;
}
void freeVertex() {
	freeV(V);
}
