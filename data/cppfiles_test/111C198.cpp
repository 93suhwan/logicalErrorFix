#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  int t, i, j, n;
  cin >> t;
  for (; t; t--) {
    cin >> n;
    for (i = 1; i <= n; i++) {
      s = "";
      for (j = 1; j <= i; j++) s += '(';
      for (j = 1; j <= i; j++) s += ')';
      for (j = 1; j <= n - i; j++) {
        s += '(';
        s += ')';
      }
      cout << s << '\n';
    }
  }
  return 0;
}
