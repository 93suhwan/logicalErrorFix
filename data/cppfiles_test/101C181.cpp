#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
T gcd(T a, T b) {
  return ((b == 0) ? a : gcd(b, a % b));
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> x(n), y(m);
  for (int i = 0; i < (int)(n); i++) cin >> x[i];
  for (int i = 0; i < (int)(m); i++) cin >> y[i];
  vector<pair<int, int> > p(k);
  for (int i = 0; i < (int)(k); i++) cin >> p[i].first >> p[i].second;
  sort(p.begin(), p.end());
  long long ans = 0LL;
  int l = 0;
  x.push_back(1e6);
  for (int i = 0; i < (int)(n + 1); i++) {
    int lst = (i ? x[i - 1] : 0);
    while (l < k && p[l].first == lst) l++;
    int fst = l;
    while (l < k && p[l].first > lst && p[l].first < x[i]) l++;
    vector<int> cr;
    for (int j = (int)(fst); j < (int)(l); j++) cr.push_back(p[j].second);
    sort(cr.begin(), cr.end());
    int tot = (int)(cr.size());
    if (!tot) continue;
    int nm = 1;
    long long nw = 0LL;
    for (int j = (int)(1); j < (int)(cr.size()); j++) {
      if (cr[j] == cr[j - 1])
        nm++;
      else {
        nw += 1LL * (long long)(nm) * (long long)(tot - nm);
        nm = 1;
      }
    }
    nw += 1LL * (long long)(nm) * (long long)(tot - nm);
    ans += nw / 2;
  }
  x = y;
  n = m;
  x.push_back(1e6);
  l = 0;
  for (int i = 0; i < (int)(k); i++) swap(p[i].first, p[i].second);
  sort(p.begin(), p.end());
  for (int i = 0; i < (int)(n + 1); i++) {
    int lst = (i ? x[i - 1] : 0);
    while (l < k && p[l].first == lst) l++;
    int fst = l;
    while (l < k && p[l].first > lst && p[l].first < x[i]) l++;
    vector<int> cr;
    for (int j = (int)(fst); j < (int)(l); j++) cr.push_back(p[j].second);
    sort(cr.begin(), cr.end());
    int tot = (int)(cr.size());
    if (!tot) continue;
    int nm = 1;
    long long nw = 0LL;
    for (int j = (int)(1); j < (int)(cr.size()); j++) {
      if (cr[j] == cr[j - 1])
        nm++;
      else {
        nw += 1LL * (long long)(nm) * (long long)(tot - nm);
        nm = 1;
      }
    }
    nw += 1LL * (long long)(nm) * (long long)(tot - nm);
    ans += nw / 2;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
