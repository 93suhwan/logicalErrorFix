#include <bits/stdc++.h>
using namespace std;
long long poww(long long n, long long r) {
  long long res = 1;
  while (r) {
    if (r & 1) res = (res * n);
    n = (n * n);
    r = r >> 1;
  }
  return res;
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
void solve() {
  long long n, k;
  cin >> n >> k;
  map<long long, vector<long long>> rec;
  map<long long, long long> mp;
  vector<long long> v(n), ans(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    mp[v[i]]++;
    if (rec[v[i]].size() < k) rec[v[i]].push_back(i);
  }
  long long tot = 0;
  for (auto i : mp) {
    tot += (min(k, i.second));
  }
  long long ctr = tot / k, curr = 1;
  long long lim = ctr * k;
  long long count = 0;
  for (auto i : rec) {
    for (auto j : i.second) {
      ans[j] = curr;
      count++;
      if (count < lim) {
        curr++;
        if (curr == k + 1) curr = 1;
      } else
        curr = 0;
    }
  }
  for (auto i : ans) cout << i << " ";
  cout << "\n";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
