#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, mod = 998244353;
int n, m, t, k;
int s[N], dp[N], f[N];
char g[N];
string str;
vector<int> vec;
map<int, int> ma;
map<pair<int, int>, int> mb;
pair<int, int> p[N];
void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> s[i];
  sort(s + 1, s + 1 + n);
  for (int i = 1; i <= m; i++) cin >> f[i];
  sort(f + 1, f + 1 + m);
  for (int i = 1; i <= k; i++) cin >> p[i].first >> p[i].second;
  long long ans = 0;
  ma.clear(), mb.clear();
  for (int i = 1; i <= k; i++) {
    int a = lower_bound(s + 1, s + 1 + n, p[i].first) - s;
    int b = lower_bound(f + 1, f + 1 + m, p[i].second) - f;
    if (s[a] == p[i].first && f[b] != p[i].second) {
      ans += ma[b]++;
      ans -= mb[{a, b}]++;
    }
  }
  ma.clear(), mb.clear();
  for (int i = 1; i <= k; i++) {
    int a = lower_bound(s + 1, s + 1 + n, p[i].first) - s;
    int b = lower_bound(f + 1, f + 1 + m, p[i].second) - f;
    if (s[a] != p[i].first && f[b] == p[i].second) {
      ans += ma[a]++;
      ans -= mb[{a, b}]++;
    }
  }
  cout << ans << '\n';
}
int main() {
  t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
