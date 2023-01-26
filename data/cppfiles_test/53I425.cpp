#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    int cn = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] != c) {
        cn++;
      }
    }
    if (cn == 0) {
      cout << "0\n";
      continue;
    }
    int p = -1;
    vector<bool> used(n + 1, false);
    for (int x = 2; x <= n; ++x) {
      if (used[x]) continue;
      bool f = true;
      for (int m = 1; m <= n / x; ++m) {
        int v = x * m;
        if (s[v - 1] != c) {
          f = false;
          break;
        }
        if (used[v]) continue;
        used[v] = true;
      }
      if (f) {
        p = x;
        break;
      }
    }
    if (p != -1) {
      cout << "1\n" << p << "\n";
    } else {
      cout << "2\n";
      cout << n - 1 << " " << n << "\n";
    }
  }
}
