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
	while (1) {
		c = takeInput(&source, &s, &d, &dest, &flag);
		command = current(c);
		switch (command) {
		case STOP:
			cout << "Query: stop" << endl;
			//cout << A[n];
			//free(A);
			for (int i = 0; i < n; i++) {
				free(A[i]);
			}
			//cout << A[n+1];
			free(node);
			//cout << getWeight(d);
			freeVertex();
			//cout << getWeight(d);
			exit(0);
			break;
		case FIND:
			noFind = 0;
			cout << "Query: find " << source << " " << dest << " " << flag << endl;
			//cout << "find command, source = " << source << ", dest = " << dest << ", flag = " << flag << endl;
			if (source > n || dest == source || flag > 1 || flag < 0) {
				//cout << source << " " << n << " " << dest << " " << flag << endl;
				cout << "Error: invalid find query" << endl;
				noFind = 1;
				break;
			}
			freeVertex();
			exists = dijkstra(n, A, source, dest, flag);
			//getComputed();
			break;
		case WRITE:
			cout << "Query: write path " << s << " " << d << endl;
			if (noFind == 1) {
				cout << "Error: no path computation done" << endl;
				break;
			}
			if (s != source || d > n) {
				cout << "Error: invalid source destination pair" << endl;
				break;
			}
			weight = getWeight(d);
			//cout << weight;
			//cout << isComputed(d) << endl;
			if (isComputed(d) == 0 && exists == 0) {
				cout << "No " << s << "-" << d << " path has been computed." << endl;
				break;
			}
			if (weight > 100000) {
				cout << "No " << s << "-" << d << " path exists." << endl;
				break;
			}
			//cout << "color d: " << getColor(d) << endl;
			if (getColor(d) == gray) {
				cout << "Path not known to be shortest: <" << s << ", ";
			}if (getColor(d) == black) {
				cout << "Shortest path: <" << s << ", ";
			}
			//cout << "Shortest path: <" << s << ", ";
			getPath(d, s);
			cout << endl;
			printf("The path weight is: %12.4f\n", weight);

			//cout << "write path command, s = " << s << ", d = " << d << endl;
			break;
		case NONE:
			//cout << endl;
			break;
		}
	}



	return 0;
}
