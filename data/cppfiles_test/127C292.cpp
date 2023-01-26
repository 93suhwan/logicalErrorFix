#include <bits/stdc++.h>
void pri(char ch, int num) {
  while (num-- > 0) {
    std::cout << ch;
  }
}
int main() {
  int t;
  std::cin >> t;
  int str[26];
  while (t-- > 0) {
    std::string S, T;
    std::cin >> S >> T;
    for (int i = 0; i < 26; i++) {
      str[i] = 0;
    }
    for (auto c : S) {
      str[c - 'a']++;
    }
    if (T == "abc" && str[0] > 0 && str[1] > 0 && str[2] > 0) {
      pri('a', str[0]);
      pri('c', str[2]);
      pri('b', str[1]);
      for (int i = 3; i < 26; i++) {
        pri('a' + i, str[i]);
      }
      std::cout << std::endl;
    } else {
      pri('a', str[0]);
      pri('b', str[1]);
      pri('c', str[2]);
      for (int i = 3; i < 26; i++) {
        pri('a' + i, str[i]);
      }
      std::cout << std::endl;
    }
  }
}
