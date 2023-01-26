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
  if (s == "Done") return 2;
  if (s[0] == 'D')
    return 1;
  else
    return 0;
}
void solve(int x, int op) {
  flag = ask(x, op);
  if (flag == 2)
    return;
  else if (flag == 1) {
    solve(x + 1, op);
    if (flag == 2) return;
  }
  for (int i = (op == 1 ? 2 : 1); i <= 8; i++) {
    if (i == op) continue;
    flag = ask(x, i);
    if (flag == 2)
      return;
    else if (flag == 1) {
      solve(x + 1, i);
      if (flag == 2) return;
    }
  }
  for (int i = 8; i >= 1; i--) {
    flag = ask(x, i);
    if (flag == 2)
      return;
    else if (flag == 1) {
      solve(x + 1, i);
      if (flag == 2) return;
    }
  }
}
int32_t main() {
  cin >> t;
  while (t--) solve(1, 1);
  return 0;
}
