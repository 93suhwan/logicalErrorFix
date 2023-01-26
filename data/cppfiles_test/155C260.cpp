#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)(1e9 + 7);
long long power(long long a, long long x) {
  if (x == 0) {
    return 1;
  }
  long long res = power(a, x / 2);
  if (x % 2) {
    res = res * res * a;
  } else {
    res = res * res;
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 0, n = 0, m, x, k;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    string s;
    cin >> s;
    vector<pair<long long, long long> > lk(0);
    vector<pair<long long, long long> > dlk(0);
    for (long long i = 0; i < n; i++) {
      if (s[i] == '1') {
        lk.push_back({a[i], i});
      } else {
        dlk.push_back({a[i], i});
      }
    }
    sort(lk.begin(), lk.end());
    sort(dlk.begin(), dlk.end());
    vector<long long> ans(n);
    long long sum = 0;
    long long z1 = dlk.size();
    long long z2 = lk.size();
    for (long long i = 0; i < z1; i++) {
      long long cmp = i + 1;
      ans[dlk[i].second] = cmp;
    }
    for (long long i = 0; i < z2; i++) {
      long long cmp = z1 + i + 1;
      ans[lk[i].second] = cmp;
    }
    for (long long i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
