#include <bits/stdc++.h>
using namespace std;
int Solution(std::string l, int len) {
  char* charArray;
  std::string string1;
std:;
  string string2;
  charArray = &l[0];
  if (len % 2 != 0) {
    std::cout << "NO" << std::endl;
    return 0;
  }
  for (int i = 0; i < len / 2; i++) {
    string1 = string1 + charArray[i];
  }
  int p = len / 2;
  for (int i = p; i != len; i++) {
    string2 = string2 + charArray[i];
  }
  if (string1.compare(string2) == 0) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
  return 0;
}
int main(void) {
  int t;
  std::string l;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    std::cin >> l;
    int len = l.size();
    Solution(l, len);
  }
  return 0;
}
