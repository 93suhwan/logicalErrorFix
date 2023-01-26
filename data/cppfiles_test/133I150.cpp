#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 1, b, c = 0, i, d = 0, e = 0, f, k = 0, j = 0, n = 0, t = 0, l = 0,
      m = 0;
  string s, x;
  cin >> t;
  j = 0;
  while (t--) {
    cin >> a;
    x = "";
    for (i = 1; i <= a - 2; i++) {
      cin >> s;
      if (i == 1)
        x += s;
      else if (s[0] == s[1] || s[0] == x[x.size() - 1])
        x += s[1];
      else
        x += s;
    }
    if (x.size() < a)
      cout << x << (x[a - 2] == 'a' ? 'b' : 'a') << endl;
    else
      cout << x << endl;
  }
  return 0;
}
