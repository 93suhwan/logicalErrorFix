#include <bits/stdc++.h>
using namespace std;
void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> pos(n + 1, 0), a(n);
  for (long long i = 0; i < (n); i++) cin >> a[i];
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  for (long long i = 0; i < (n); i++) {
    if (a[i] >= 1 and a[i] <= n and pos[a[i]] == 0)
      pos[a[i]] = 1;
    else
      pq.push(a[i]);
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    if (pos[i] == 1) continue;
    long long min_possible = pq.top();
    pq.pop();
    if (min_possible >= (2 * i + 1))
      ans++;
    else {
      cout << -1 << "\n";
      return;
    }
  }
  cout << ans << "\n";
}
signed main() {
  init();
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
