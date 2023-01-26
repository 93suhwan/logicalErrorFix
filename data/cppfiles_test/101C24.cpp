#include <bits/stdc++.h>
using namespace std;
void write(vector<long long> &v) {
  for (auto i : v) cout << i << " ";
  cout << "\n";
}
void read(vector<long long> &v) {
  for (auto &i : v) cin >> i;
}
const long long INF = 1e9;
const int64_t INFF = 1e18;
const long long N = 1e6 + 69;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> x(n);
  read(x);
  vector<long long> y(m);
  read(y);
  vector<pair<long long, long long>> v(k);
  for (long long i = 0; i < k; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort((v).begin(), (v).end());
  long long j = 0;
  long long ans = 0;
  map<long long, long long> m1;
  for (long long i = 0; i < n; i++) {
    long long cnt = 0;
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
  for (long long i = 0; i < k; i++) {
    swap(v[i].first, v[i].second);
  }
  sort((v).begin(), (v).end());
  j = 0;
  for (long long i = 0; i < m; i++) {
    long long cnt = 0;
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
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
