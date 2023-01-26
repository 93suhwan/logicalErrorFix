#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > a(n);
  vector<pair<long long, long long> > b(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (long long i = 0; i < n; i++) {
    cin >> b[i].first;
    b[i].second = i;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<long long> can(n, 0);
  long long x = b.back().second;
  bool good = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i].second == x) good = 1;
    if (good) can[a[i].second] = 1;
  }
  x = a.back().second;
  good = 0;
  for (long long i = 0; i < n; i++) {
    if (b[i].second == x) good = 1;
    if (good) can[b[i].second] = 1;
  }
  for (long long i : can) cout << i;
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  while (n--) {
    solve();
  }
}
