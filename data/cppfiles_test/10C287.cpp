#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  map<long long, vector<long long>> m;
  for (long long i = (long long)0; i < n; i++) {
    long long x;
    cin >> x;
    m[x].push_back(i);
  }
  vector<long long> ans(n, 0);
  vector<long long> a(k);
  for (long long i = (long long)0; i < k; i++) a[i] = i + 1;
  long long i = 0;
  long long lim = 0;
  for (auto x : m) {
    lim += min(k, (long long)x.second.size());
  }
  lim = (lim / k) * k;
  for (auto x : m) {
    long long cnt = 0;
    long long z = x.second.size();
    long long j = 0;
    while (cnt < min(k, z)) {
      ans[x.second[j]] = a[i % k];
      cnt++;
      i++;
      j++;
      if (i >= lim) break;
    }
    if (i >= lim) break;
  }
  for (long long i = (long long)0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
