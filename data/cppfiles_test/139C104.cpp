#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const double eps = 1e-9;
const int mod = 1e9 + 7;
const int nax = 205;
int powr(int x, int p) {
  if (p == 0) return 1;
  int xx = powr(x, p / 2);
  xx = (1LL * xx * xx) % mod;
  if (p & 1) xx = (1LL * xx * x) % mod;
  return xx;
}
int n, m;
int lim = (1 << 9);
void solve(int tc) {
  string ss;
  cin >> ss;
  if (ss.length() % 2) {
    cout << "NO\n";
    return;
  }
  int l = ss.length() / 2;
  for (int i = 0; i < l; ++i) {
    if (ss[i] != ss[i + l]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}
int main() {
  int tt = 1;
  scanf("%d", &tt);
  for (int i = 1; i <= tt; ++i) {
    solve(i);
  }
  return 0;
}
