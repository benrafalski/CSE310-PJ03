#include <iostream>
#include <string>
#include "util.h"
#include "heap.h"
#include "graph.h"
using namespace std;



string filename = "";
int main(int argc, char* argv[]) {
	if (argc > 1) {
		filename = argv[1];
	}
	string uord = argv[2];
	//cout << uord;
	char c;
	int source, s, d, dest, flag;
	int noFind = 0;
	float weight;
	commands command;
	int exists;
	//string filename = "input.txt";
	ifstream inFile;
	ptrNode node = NULL;
	ptrNode* A = NULL;
	int n, m, id, u, v;
	float w;
	inFile.open(filename);
	if (inFile.is_open()) {
		inFile >> n >> m;
		//cout << n;
		//initializeGraph(n);
		A = (ptrNode*)calloc(n + 1, sizeof(ptrNode));
		for (int i = 0; i < m; i++) {
			inFile >> id >> u >> v >> w;
			node = (ptrNode)malloc(sizeof(NODE));
			node->v = v;
			node->w = w;
			node->next = A[u];
			A[u] = node;
			//undirected
			if (uord.compare("undirected") == 0) {
				//cout << "here" << endl;
				node = (ptrNode)malloc(sizeof(NODE));
				node->v = u;
				node->w = w;
				node->next = A[v];
				A[v] = node;
				//free(node);
			}
		}
		/*
		for (int i = 1; i <= n; i++) {
			cout << "node " << i << ":" << endl;
			node = A[i];
			while (node) {
				cout << node->v << "," << node->w << endl;
				node = node->next;
			}
		}
//		*/
		inFile.close();
		//free(A);
		//dijkstra(n, A, 1, 9);
	}
	//readGraph(filename);
}
