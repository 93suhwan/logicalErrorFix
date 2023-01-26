#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> a(n), b(n);
  vector<long long> aa(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first;
    aa[i] = a[i].first;
    a[i].second = i;
  }
  vector<long long> bb(n);
  for (long long i = 0; i < n; i++) {
    cin >> b[i].first;
    bb[i] = b[i].first;
    b[i].second = i;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  string res = string(n, '0');
  auto relax = [&]() {
    long long cnt = 0, mx_b = 0, ptr = 0;
    vector<long long> used(n);
    for (long long i = 0; i < n; i++) {
      if (!used[a[i].second]) {
        used[a[i].second] = 1;
        cnt++;
      }
      mx_b = max(mx_b, bb[a[i].second]);
      while (ptr < n && b[ptr].first < mx_b) {
        if (!used[b[ptr].second]) {
          used[b[ptr].second] = 1;
          cnt++;
        }
        ptr++;
      }
      if (cnt == n) {
        res[a[i].second] = '1';
      }
    }
  };
  relax();
  swap(a, b);
  swap(aa, bb);
  relax();
  cout << res << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long tc;
  cin >> tc;
  while (tc-- > 0) solve();
  return 0;
}
