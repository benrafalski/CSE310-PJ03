#include <iostream>
#include <string>

int takeInput(int* source, int* s, int* d, int* dest, int* flag);
enum commands { FIND, WRITE, STOP, NONE }; // forward declaration of commands enum type
commands current(char c);
