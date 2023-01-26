#include <bits/stdc++.h>
using namespace std;
bool done[3001][3001];
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long>> a(m);
  for (long long i = 0; i < m; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end(), cmp);
  long long ans = 0;
  for (long long i = 0; i < m; i++) {
    long long dis = 0;
    if (i == 0 or a[i].second == 0) continue;
    for (long long j = 0; j < i; j++) {
      if (a[j].second < a[i].second) dis++;
    }
    ans += dis;
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long tc = 1;
  cin >> tc;
  for (long long i = 1; i <= tc; i++) {
    solve();
  }
}
