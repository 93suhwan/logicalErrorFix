#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const int INF = 1000000007;
const long long INF_LL = 1152921504606846977;
void files_io() {
  freopen("", "r", stdin);
  freopen("", "w", stdout);
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = INF;
  for (char c = 'a'; c <= 'z'; ++c) {
    int l = 0, r = n - 1, cnt = 0;
    vector<int> del(n);
    while (l < r) {
      if (s[l] == s[r]) {
        ++l, --r;
      } else {
        if (s[l] == c) {
          ++cnt;
          del[l++] = 1;
        } else if (s[r] == c) {
          ++cnt;
          del[r--] = 1;
        } else {
          cnt = INF;
          break;
        }
      }
    }
    string s1, s2;
    for (int i = 0; i < n; ++i) {
      if (!del[i]) s1 += s[i];
      if (!del[n - i - 1]) s2 += s[n - i - 1];
    }
    if (s1 == s2) ans = min(ans, cnt);
  }
  cout << (ans == INF ? -1 : ans) << '\n';
}
signed main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  cout << fixed << setprecision(20);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
}
