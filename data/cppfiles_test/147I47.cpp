#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f, g, i, j, k, l, m, n;
  long long int t, T;
  cin >> T;
  for (t = 1; t <= T; t++) {
    string s;
    cin >> s;
    l = s.length();
    if (s[0] == s[l - 1]) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
