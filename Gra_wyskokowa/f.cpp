#include <iostream>
#include <cstring>
using namespace std;
extern "C" {
	int f(char *a1,char *a2)
	{
		char word[30];

		strcpy_s(word,30, a2);
		strcpy_s(a2,30, a1);
		strcpy_s(a1,30, word);
		return 0;
	}
}