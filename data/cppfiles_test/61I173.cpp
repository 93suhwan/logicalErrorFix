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
  for (int i = 1; i < n + 1; i++) {
    if (s[i].size() >= 2) {
      long long y = s[i].size();
      long long sum = 0;
      for (auto bb : s[i]) {
        if (g[a[bb].second].size() != 0) {
          sum += g[a[bb].second].size();
          sum--;
        }
      }
      ans -= (sum * (y - 1));
    }
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
