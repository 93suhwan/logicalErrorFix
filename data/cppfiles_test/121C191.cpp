#include <bits/stdc++.h>
using namespace std;
int v[100005];
int v1[100005];
int main() {
  int n, j, k, l, z, t, x, i, cop, a, b, cnt, sumacurr;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char ch;
  cin >> t;
  int maxim = 0;
  for (z = 1; z <= t; z++) {
    int difer1 = 0;
    int difer0 = 0;
    int egal1 = 0;
    int egal0 = 0;
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> ch;
      v[i] = ch - '0';
    }
    for (i = 1; i <= n; i++) {
      cin >> ch;
      v1[i] = ch - '0';
    }
    for (i = 1; i <= n; i++) {
      if (v[i] != v1[i]) {
        if (v[i] == 1) {
          difer1++;
        } else {
          difer0++;
        }
      } else {
        if (v[i] == 1) {
          egal1++;
        } else {
          egal0++;
        }
      }
    }
    int sol = 10e7 + 9;
    if (egal1 + egal0 == n) {
      sol = min(sol, 0);
    }
    if (difer1 == difer0) {
      sol = min(sol, difer0 + difer1);
    }
    if (egal1 == egal0 + 1) {
      sol = min(sol, egal1 + egal0);
    }
    if (sol == 10e7 + 9) {
      cout << -1;
    } else {
      cout << sol;
    }
    cout << '\n';
  }
  return 0;
}
