#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 10010;
const int MAXL = 2010;
int n;
int x[MAXN];
bool f[2][MAXL];
bool Check(int L) {
  memset(f[0], 0, sizeof(f[0][0]) * (L + 1));
  memset(f[1], 0, sizeof(f[1][0]) * (L + 1));
  for (int i = 0; i >= x[0] - L; --i) {
    f[0][min(x[0] - i, L - x[0] + i)] = true;
  }
  int o = 0;
  for (int i = 1; i < n; ++i) {
    o ^= 1;
    memset(f[o], 0, sizeof(f[o][0]) * (L + 1));
    for (int j = 0; j <= L; ++j) {
      if (f[o ^ 1][j]) {
        if (j >= x[i]) {
          f[o][j - x[i]] = true;
        }
        if (L - j >= x[i]) {
          f[o][min(L - j - x[i], j + x[i])] = true;
        }
      }
    }
  }
  for (int i = 0; i <= L; ++i) {
    if (f[o][i]) return true;
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    cin >> n;
    int L = 0, R = 0;
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
      L = max(L, x[i]);
    }
    R = L + L;
    L = L - 1;
    while (L + 1 < R) {
      int mid = (L + R) >> 1;
      if (Check(mid))
        R = mid;
      else
        L = mid;
    }
    cout << R << "\n";
  }
  return 0;
}
