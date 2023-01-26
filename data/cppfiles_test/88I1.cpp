#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool comp(pair<int, int> f, pair<int, int> s) {
  if (f.first == s.first) return f.second > s.second;
  return f.first < s.first;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n * m, {0, n * m + 1});
  for (int i = 0; i < n * m; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end(), comp);
  int ans = 0;
  for (int i = 0; i < n * m; i++) {
    for (int j = 0; j < i; j++) {
      if (a[i].second > a[j].second) {
        ans++;
      }
    }
  }
  cout << ans << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
