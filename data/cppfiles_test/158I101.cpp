#include <bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector,unroll-loops")
#pragma GCC target("avx2,fma")
using namespace std;
const long long inf = 1e18, N = 1e4 + 10, maxn = 11, mod = 1e9 + 7,
                pr = 1000696969;
int x[maxn], st[N], dp[N];
vector<pair<int, int> > vc;
string s[maxn];
inline void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) cin >> s[i];
  int ans = 0, ans_t = 0;
  for (int mask = 0; mask < (1 << n); mask++) {
    vc.clear();
    ans = 0;
    for (int j = 0; j < m; j++) dp[j] = 0;
    for (int j = 0; j < n; j++) {
      if (mask & (1 << j)) {
        ans += x[j];
        for (int k = 0; k < m; k++) {
          if (s[j][k] == '1') {
            dp[k]--;
          }
        }
      } else {
        ans -= x[j];
        for (int k = 0; k < m; k++) {
          if (s[j][k] == '1') {
            dp[k]++;
          }
        }
      }
    }
    for (int i = 0; i < m; i++) {
      vc.push_back({dp[i], i});
    }
    sort((vc).begin(), (vc).end());
    for (int i = int((vc).size()) - 1; i >= 0; i--) {
      ans += vc[i].first * (i + 1);
    }
    if (ans > ans_t) {
      for (int i = int((vc).size()) - 1; i >= 0; i--) {
        st[vc[i].second] = i + 1;
      }
      ans_t = ans;
    }
  }
  for (int i = 0; i < m; i++) cout << st[i] << " ";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
