#include <bits/stdc++.h>
using namespace std;
void write(vector<int> &v) {
  for (auto i : v) cout << i << " ";
  cout << "\n";
}
void read(vector<int> &v) {
  for (auto &i : v) cin >> i;
}
const int INF = 1e9;
const int64_t INFF = 1e18;
const int N = 1e6 + 69;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> x(n);
  read(x);
  vector<int> y(m);
  read(y);
  vector<pair<int, int>> v(k);
  for (int i = 0; i < k; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort((v).begin(), (v).end());
  int j = 0;
  int ans = 0;
  map<int, int> m1;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    while (j < k && v[j].first <= x[i]) {
      if (v[j].first < x[i]) {
        ans += cnt - m1[v[j].second];
        cnt++;
        m1[v[j].second]++;
      }
      j++;
    }
    m1.clear();
  }
  for (int i = 0; i < k; i++) {
    swap(v[i].first, v[i].second);
  }
  sort((v).begin(), (v).end());
  j = 0;
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    while (j < k && v[j].first <= y[i]) {
      if (v[j].first < y[i]) {
        ans += cnt - m1[v[j].second];
        cnt++;
        m1[v[j].second]++;
      }
      j++;
    }
    m1.clear();
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
