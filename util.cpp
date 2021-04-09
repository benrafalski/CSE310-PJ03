#include <iostream>
#include <string>
#include "util.h"
using namespace std;


int takeInput(int* source, int* s, int* d, int* dest, int* flag) {
	string input;
	string catchMe;
	string a[10] = {};
	int i = 0;
	char value = ' ';
	while (1) {
		cin >> input;
		while (input.compare("\n") == 0 || input.compare(" ") == 0) {
			cin >> input;
			
		}
		if (input.compare("find") == 0) {
			getline(cin, catchMe, '\n');
			//cout << catchMe;

			string delim = " ";
			catchMe += delim;
			size_t pos = 0;
			std::string::size_type sz;
			//cout << catchMe
			string token;
			while ((pos = catchMe.find(delim)) != std::string::npos) {
				token = catchMe.substr(0, pos);
				a[i] = token;
				//std::cout << a[i] << std::endl;
				catchMe.erase(0, pos + delim.length());
				i++;
			}
			
			//cout << a[1] << endl;
			*source = stoi(a[1], &sz);
			*dest = stoi(a[2], &sz);
			//cout << "source:" << *source << endl;
			//cout << a[2] << endl;
			if (a[3].compare("") == 0) {
				break;
			}
			*flag = stoi(a[3], &sz);
			//cout << a[3] << endl;
			//cout << "here" << endl;
			
			/*
			*source = stoi(token, &sz);
			token = catchMe.substr(2, 3);
			*dest = stoi(token, &sz);
			//cout << catchMe.length();
			if (catchMe.length() == 4) {
				cout << "here";
				return value;
			}
			token = catchMe.substr(4, 5);
			//cout << token << endl;
			*flag = stoi(token, &sz);
			//cout << *flag << endl;
			//cout << f << endl;
			//cout << catchMe;
			//cin >> *source;
			//cin >> *dest;
			//scanf_s("%d", dest);
			//cout << *dest;
			//cout << "here";
			//cout << *dest << endl;
			//cin >> *flag;
			value = 'f';
			*/
			value = 'f';
			//delete &a;
			break;
			
		}
		if (input.compare("path") == 0) {
			cin >> *s;
			cin >> *d;
			value = 'p';
			break;
		}
		if (input.compare("stop") == 0) {
			value = 's';
			break;
		}
	}
	//delete a;
	return value;




}
