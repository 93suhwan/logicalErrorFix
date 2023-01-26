#include <bits/stdc++.h>
using namespace std;
const int c = 100005;
long long n;
vector<long long> a;
bool read() {
  if (!(cin >> n)) return false;
  a.resize(n + 1);
  for (long long i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  return true;
}
void solve() {
  long long n;
  cin >> n;
  vector<vector<long long>> v(n);
  for (long long i = 0; i < n; ++i) {
    long long k;
    cin >> k;
    vector<long long> temp(k);
    for (long long j = 0; j < k; ++j) {
      cin >> temp[j];
    }
    v[i] = temp;
  }
  auto id = max_element(v[0].begin(), v[0].end()) - v[0].begin();
  long long maxx = v[0][id] + 1 - id;
  if (v[0][0] == v[0][id] - 1) maxx++;
  long long ans = maxx;
  for (long long i = 1; i < n; ++i) {
    id = max_element(v[i].begin(), v[i].end()) - v[i].begin();
    maxx = v[i][id] + 1 - id;
    if (v[i][0] == v[i][id] - 1) maxx++;
    if (maxx < ans and maxx + v[i].size() >= ans) ans = maxx;
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
