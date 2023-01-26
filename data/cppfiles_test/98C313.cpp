#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, j, a, b, c, d, e;
  string s, l;
  cin >> t;
  while (t--) {
    cin >> s >> l;
    int sum = 0;
    for (j = 0; j < 26; j++) {
      if (s[j] == l[0]) {
        a = j;
      }
    }
    for (i = 1; i < l.length(); i++) {
      for (j = 0; j < 26; j++) {
        if (s[j] == l[i]) {
          b = j;
          sum += abs(b - a);
          a = b;
        }
      }
    }
    cout << sum << '\n';
  }
  return 0;
}
