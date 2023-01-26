#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
T gcd(T a, T b) {
  return ((b == 0) ? a : gcd(b, a % b));
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int> > p;
  for (int i = 0; i < (int)(n); i++) {
    int k;
    cin >> k;
    vector<int> a(k);
    int mx = 0;
    for (int j = 0; j < (int)(k); j++) {
      cin >> a[j];
      mx = max(mx, a[j] - j);
    }
    p.push_back(make_pair(mx, k));
  }
  sort(p.begin(), p.end());
  int l = 0, r = 1e9 + 10;
  while (l < r) {
    int mid = (l + r) / 2;
    int cur = mid;
    int f = 1;
    for (int j = 0; j < (int)(n); j++) {
      if (cur <= p[j].first) f = 0;
      cur += p[j].second;
    }
    if (f)
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
