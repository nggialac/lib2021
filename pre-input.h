#include "prototype.h"

#ifndef preInput
#define preInput

char* toCharArray(string str) {
	char* c = new char(str.size() + 1);
	for (int i = 0; i < str.size() + 1; i++)
		c[i] = str[i];
	return c;
}

string chuanHoaChuoi(string result) {
	for (size_t i = 1; i < result.length(); i++) {
		if (result[0] == ' ') {
			result.erase(0, 1);
			i--;
		} else if (result[i - 1] == ' ' && result[i] == ' ') {
			result.erase(i - 1, 1);
			i--;
		} else if (result[result.length() - 1] == ' ') {
			result.erase(result.length() - 1, 1);
		}
	}
	return result;
}


#endif