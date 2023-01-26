#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("-Ofast", "-funroll-all-loops", "-ffast-math")
#pragma GCC target("avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int inf = 0x3f3f3f3f;
const long long lnf = 0x7f7f7f7f7f7f7f7f;
const double eps = 1e-6;
const double pi = acos(-1.0);
const int mod = 998244353;
const int N = 1e6 + 10;
const int M = 1e7 + 10;
int t, flag;
string s;
int ask(int x, int y) {
  cout << x << " " << y << '\n';
  cout.flush();
  cin >> s;
  if (s == "Done")
    return 2;
  else if (s == "Left" || s == "Down-Left" || s == "Up-Left")
    return 1;
  else
    return 0;
}
void solve(int x) {
  for (int i = 1; i <= 7; i++) {
    flag = ask(x, i);
    if (flag == 2) break;
    if (flag == 1) {
      flag = ask(x + 1, i);
      if (flag == 2)
        break;
      else
        solve(x + 1);
    }
  }
}
int32_t main() {
  cin >> t;
  while (t--) solve(1);
  return 0;
}
