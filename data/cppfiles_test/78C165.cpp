#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int mxN = 2021;
void solve() {
  int l, r;
  cin >> l >> r;
  int x = (r + 2) >> 1;
  cout << r - max(x, l);
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt = 1;
  cin >> tt;
  for (int _ = 1; _ <= tt; _++) {
    solve();
    cout << "\n";
  }
  return 0;
}
