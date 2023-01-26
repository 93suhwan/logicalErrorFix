#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2;
int a[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, n;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    n = s.size();
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < (int)n; i++) {
      if (s[i] == 'A')
        x++;
      else if (s[i] == 'C')
        y++;
      else
        z++;
    }
    bool ok = 1;
    if (2 * z != n || x + y != z) {
      ok = 0;
    }
    if (ok)
      for (int i = 0; i < (int)n; i++) {
        if (s[i] != 'B') {
          int u = 0;
          if (i - 1 >= 0 && s[i - 1] == 'B') u++;
          if (i + 1 < n && s[i + 1] == 'B') u++;
          if (z - u <= 0) ok = 0;
        }
      }
    cout << (ok ? "YES\n" : "NO\n");
  }
}
