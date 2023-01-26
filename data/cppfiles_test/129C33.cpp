#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  deque<long long> dek;
  map<long long, long long> mp;
  for (long long i = 0, x; i < n; i++) {
    cin >> x;
    if (x <= n && !mp[x])
      mp[x]++;
    else
      dek.push_back(x);
  }
  sort(dek.begin(), dek.end());
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    if (mp[i] == 1) continue;
    if (dek.front() <= 2 * i) {
      cout << -1 << '\n';
      return;
    }
    dek.pop_front();
    ans++;
  }
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
