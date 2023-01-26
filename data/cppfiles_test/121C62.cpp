#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
constexpr long long MOD = 1e9 + 7;
constexpr long long inf = 1e16;
constexpr int MAXN = 1e5 + 5;
int n;
int helper(int type, int l_c, int l_s, int nl_c, int nl_s) {
  for (int i = 0; i <= n; i++) {
    if (l_c == 0 && nl_c == 0) {
      return i;
    }
    if (i % 2 == type) {
      if (l_c == 0) {
        return INT_MAX;
      }
      swap(l_c, nl_s);
      swap(l_s, nl_c);
      l_c += 1;
      nl_s -= 1;
    } else {
      if (l_s == 0) {
        return INT_MAX;
      }
      swap(l_c, nl_s);
      swap(l_s, nl_c);
      nl_c -= 1;
      l_s += 1;
    }
  }
  return INT_MAX;
}
void solve() {
  string s1, s2;
  cin >> n >> s1 >> s2;
  int l_c = 0, l_s = 0;
  int nl_c = 0, nl_s = 0;
  for (int i = 0; i < n; i++) {
    if (s1[i] == '1') {
      if (s1[i] != s2[i]) {
        ++l_c;
      } else {
        ++l_s;
      }
    } else {
      if (s1[i] != s2[i]) {
        ++nl_c;
      } else {
        ++nl_s;
      }
    }
  }
  int ans =
      min(helper(0, l_c, l_s, nl_c, nl_s), helper(1, l_c, l_s, nl_c, nl_s));
  if (ans == INT_MAX) {
    ans = -1;
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int32_t testcases = 1;
  cin >> testcases;
  for (int32_t i = 1; i <= testcases; ++i) {
    solve();
  }
  return 0;
}
