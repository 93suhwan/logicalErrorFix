#include <bits/stdc++.h>
using namespace std;
void _mak_() {
  int n;
  cin >> n;
  vector<pair<int, int> > a;
  vector<vector<long long> > s(n + 1, vector<long long>()),
      g(n + 1, vector<long long>());
  for (int i = 0; i < n; i++) {
    int r, f;
    cin >> r >> f;
    a.push_back({r, f});
    s[r].push_back(i);
    g[f].push_back(i);
  }
  long long ans = (n * (n - 1) * (n - 2)) / 6;
  for (int i = 0; i < n; i++) {
    long long v = s[a[i].first].size();
    v--;
    long long d = g[a[i].second].size();
    d--;
    ans -= (v * d);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    _mak_();
  }
  return 0;
}
