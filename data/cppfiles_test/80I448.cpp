#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
constexpr long long pct(long long x) { return __builtin_popcount(x); }
const long long DFS_WHITE = 0;
const long long DFS_BLACK = 1;
const long long INF = 1e18;
const long long MAXN = 1005;
const long long MOD = 1000000007;
void setIO(string filename = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (filename.size() == 0) return;
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}
long long n;
void solve() {
  cin >> n;
  char s[n + 1];
  for (long long i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (long long i = n; i > 0; i--) {
    if (s[i] == '0') {
      if (i > n / 2) {
        cout << "1 " << i << " 1"
             << " " << i - 1;
        return;
      }
    }
  }
  cout << n / 2 << " " << n - 1 << " " << n / 2 + 1 << " " << n;
}
signed main() {
  setIO();
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
    if (test) cout << endl;
  }
}
