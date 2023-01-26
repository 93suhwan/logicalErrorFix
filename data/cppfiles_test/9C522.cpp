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
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size() - 1; ++i) {
      if (s[i] == s[i + 1]) {
        count++;
      } else {
        if (count >= 2) {
          dupl++;
        }
        count = 1;
      }
      if (i == s.size() - 2) {
        if (count >= 2) {
          dupl++;
        }
      }
    }
    set<char> si;
    for (int i = 0; i < s.size(); ++i) {
      si.insert(s[i]);
    }
    if (si.size() == 1) {
      cout << 1 << '\n';
      continue;
    }
    cout << dupl + (si.size() - dupl) / 2 << '\n';
  }
}
