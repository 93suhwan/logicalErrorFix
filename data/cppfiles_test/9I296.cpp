#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() == 1) {
      cout << 0 << '\n';
      continue;
    }
    int count = 1;
    int dupl = 0;
    int g = 1;
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size() - 1; ++i) {
      if (s[i] == s[i + 1]) {
        count++;
      } else {
        g++;
        dupl = max(count, dupl);
        count = 0;
      }
    }
    if (g == 1) {
      cout << 1 << '\n';
      continue;
    }
    if (dupl > 2) {
      cout << (g + 2) / 2 << '\n';
    } else {
      cout << s.size() / 2 << '\n';
    }
  }
}
