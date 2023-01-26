#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
constexpr long long pct(long long x) { return __builtin_popcount(x); }
const long long DFS_WHITE = 0;
const long long DFS_BLACK = 1;
const long long INF = 1e18;
const long long MAXN = 2e5 + 10;
const long long MOD = 1e9 + 7;
void setIO(string filename = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (filename.size() == 0) return;
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}
long long n, m;
void solve() {
  cin >> n >> m;
  if (m > n) {
    swap(n, m);
  }
  if ((m + n) % 2 == 0) {
    long long tmp = (n + m) / 2;
    cout << (n - tmp + m * 2 - (n - tmp)) << endl;
    for (long long i = n - tmp; i <= n - tmp + m * 2; i += 2) {
      cout << i << " ";
    }
  } else {
    vector<long long> ans;
    long long tmp = (n + m + 1) / 2;
    for (long long i = n - tmp; i <= n - tmp + m * 2; i += 2) {
      ans.push_back(i);
    }
    tmp = (n + m - 1) / 2;
    for (long long i = n - tmp; i <= n - tmp + 2 * m; i += 2) {
      ans.push_back(i);
    }
    vector<long long> res;
    long long cur = 0;
    res.push_back(ans[cur]);
    for (long long i = 0; i < ans.size(); i++) {
      if (ans[i] != ans[cur]) {
        cur++;
        res.push_back(ans[i]);
      }
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (long long i = 0; i < res.size(); i++) {
      cout << res[i] << " ";
    }
  }
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
