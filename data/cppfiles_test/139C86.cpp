#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, x, i, j, k, p, s, f;
  string st;
  cin >> t;
  while (t--) {
    cin >> st;
    x = st.size();
    if (x % 2 == 1)
      cout << "NO\n";
    else {
      p = x / 2;
      f = 0;
      for (i = 0; i < p; i++) {
        for (j = 0; j <= i; j++) {
          if (st[j] != st[p + j]) {
            f = 1;
            break;
          }
        }
        if (f == 1) break;
      }
      if (f == 0)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }
}
