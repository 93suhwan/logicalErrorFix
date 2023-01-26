#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string s, c;
  int k;
  int a[100];
  while (t--) {
    cin >> c;
    for (int i = 0; i < c.size(); i++) {
      a[c[i] - 48] = i + 1;
    }
    cin >> s;
    k = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 's') {
        cout << k << "\n";
        continue;
      }
      if (i == s.size() - 1 && s[i] != 's') cout << k << "\n";
      k += abs(a[s[i] - 48] - a[s[i + 1] - 48]);
    }
  }
}
