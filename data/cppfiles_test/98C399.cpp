#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int x = 0; x < t; x++) {
    string s;
    cin >> s;
    string s1;
    cin >> s1;
    int sum = 0;
    if (s1.length() == 1) {
      cout << 0 << "\n";
      continue;
    }
    for (int i = 0; i < s1.length() - 1; i++) {
      int k1, k2;
      for (int j = 0; j < s.length(); j++) {
        if (s1[i] == s[j]) {
          k1 = j;
        }
      }
      for (int j = 0; j < s.length(); j++) {
        if (s1[i + 1] == s[j]) {
          k2 = j;
        }
      }
      sum = sum + abs(k2 - k1);
    }
    cout << sum << "\n";
  }
}
