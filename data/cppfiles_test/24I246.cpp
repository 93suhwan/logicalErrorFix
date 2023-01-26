#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int MAX = 1000000000;
const int inf = 1e9;
const long double PI = 3.141592653589793238460;
int max(int a, int b) {
  if (a > b) return a;
  return b;
}
void solve() {
  int n;
  cin >> n;
  if (n < 9) {
    cout << 0 << '\n';
    return;
  }
  if (n == 9)
    cout << 1 << '\n';
  else
    cout << n / 10 << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
