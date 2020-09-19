#ifndef UTIL_H
#define UTIL_H

#include <string>

using namespace std;

enum Direction;

size_t myStrGetTok(const string&, string&, size_t, const char);
bool myStr2Int(const string& str, int& num);
Direction maxValue(int[]);


#endif // UTIL_H