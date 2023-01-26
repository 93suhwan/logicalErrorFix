#include <bits/stdc++.h>
using namespace std;
int Solution(std::string l) {
  char* charArray;
  std::string string1;
std:;
  string string2;
  charArray = &l[0];
  int len = sizeof(charArray) / sizeof(charArray[0]);
  std::sort(charArray, charArray + len);
  if (len % 2 > 0) {
    std::cout << "NO" << std::endl;
    return 0;
  }
  for (int i = 0; i < len / 2; i++) {
    string1 = charArray[i];
  }
  for (int i = (len / 2) + 1; i < len; i++) {
    string2 = charArray[i];
  }
  if (string1 == string2) {
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
    Solution(l);
  }
  return 0;
}
