#include <utility.h>
#include <string>

using namespace std;

/**
 * seperate first token from a string
 * @param str input string
 * @param tok first token seperate by del in str
 * @param pos start position
 * @param del seperate key
 * return the position of end position of tok
**/
size_t 
myStrGetTok(const string& str, string& tok, size_t pos = 0,
            const char del = ' ')
{
   size_t begin = str.find_first_not_of(del, pos);
   if (begin == string::npos) { tok = ""; return begin; }
   size_t end = str.find_first_of(del, begin);
   tok = str.substr(begin, end - begin);
   return end;
}


/**
 * convert string to int
 * @param str target string
 * @param num result int
 * return false if invalid input
**/
bool myStr2Int(const string& str, int& num)
{
   num = 0;
   size_t i = 0;
   int sign = 1;
   if (str[0] == '-') { sign = -1; i = 1; }
   if (str[0] == '+') { sign =  1; i = 1; }
   bool valid = false;
   for (; i < str.size(); ++i) {
      if (isdigit(str[i])) {
         num *= 10;
         num += int(str[i] - '0');
         valid = true;
      }
      else return false;
   }
   num *= sign;
   return valid;
}
