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
int t;
string s;
bool ask(int x, int y) {
  cout << x << " " << y << '\n';
  cout.flush();
  cin >> s;
  if (s[0] == 'D') return true;
  return false;
}
int32_t main() {
  cin >> t;
  while (t--) {
    bool flag = 0;
    for (int i = 1; i <= 7; i++) {
      flag = ask(1, i);
      if (flag) break;
    }
    if (flag) continue;
    for (int i = 2; i <= 7; i++) {
      flag = ask(i, 7);
      if (flag) break;
    }
  }
  return 0;
}
