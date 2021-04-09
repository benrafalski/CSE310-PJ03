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
