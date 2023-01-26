#include <bits/stdc++.h>
#pragma optimize(3, "-Ofast", "inline")
using namespace std;
const int maxn = 1e5 + 3, maxm = 1e6 + 11, inf_int = 0x3f3f3f3f;
const long long inf_ll = 0x3f3f3f3f3f3f3f, mod = 1e9 + 7;
const double eps = 1e-6;
int n, b[maxn];
inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) {
    if (b[i] < n) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) cout << "1 ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int TEST = 1;
  cin >> TEST;
  while (TEST--) solve();
}
