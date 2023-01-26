#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long P = 998244353;
const long long N = 2e5 + 10;
long long n;
vector<long long> bit;
void update(long long p, long long x) {
  for (; p <= n; p += p & (-p)) bit[p] += x;
}
long long query(long long p) {
  long long ret = 0;
  for (; p; p -= p & (-p)) ret += bit[p];
  return ret;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    cin >> n;
    bit = vector<long long>(n + 1);
    vector<long long> a(n), hsh(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      hsh[i] = a[i];
    }
    sort(hsh.begin(), hsh.end());
    hsh.resize(unique(hsh.begin(), hsh.end()) - hsh.begin());
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      a[i] = lower_bound(hsh.begin(), hsh.end(), a[i]) - hsh.begin() + 1;
      ans += min(query(a[i] - 1), i - query(a[i]));
      update(a[i], 1);
    }
    cout << ans << '\n';
  }
  return 0;
}
