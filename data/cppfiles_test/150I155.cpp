#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e16;
const int N = 1e6 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    bool has1 = 0;
    int mx0 = -1;
    int mx1 = -1;
    int mx2 = -1;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x % 3 == 0) mx0 = max(mx0, x);
      if (x % 3 == 1) mx1 = max(mx1, x);
      if (x % 3 == 2) mx2 = max(mx2, x);
      if (x == 1) has1 = 1;
    }
    if (mx1 == -1 && mx2 == -1)
      cout << mx0 / 3 << '\n';
    else {
      if (mx1 != -1 && mx2 != -1) {
        int u = max({mx1, mx2, mx0});
        if (u == mx0) cout << mx0 / 3 + 1 << '\n';
        if (u == mx2) cout << mx2 / 3 + 2 << '\n';
        if (u == mx1) {
          if (!has1)
            cout << mx1 / 3 + 1 << '\n';
          else
            cout << mx1 / 3 + 2 << '\n';
        }
      } else
        cout << max({mx0, mx1, mx2}) / 3 + 1 << '\n';
    }
  }
  return 0;
}
