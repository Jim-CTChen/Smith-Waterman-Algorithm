#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>

using namespace std;

size_t myStrGetTok(const string&, string&, size_t, const char);
bool myStr2Int(const string& str, int& num);
vector<int> maxValue(vector<int>);


#endif // UTIL_H