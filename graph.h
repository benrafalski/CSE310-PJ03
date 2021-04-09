#include <iostream>
#include <fstream>
#include <string>

using namespace std;

///*
//enum color{white, gray, black};
typedef struct Vert {
	int color;
	int pi;
	float dist;
	//int pos;
}VERT;
typedef VERT* ptrVert;
//*/
typedef struct Node {
	int v;
	float w;
	Node* next;
}NODE;
typedef NODE* ptrNode;
