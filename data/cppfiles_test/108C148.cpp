#include <bits/stdc++.h>
using namespace std;
long long denom = 998244353;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= denom;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % denom;
    a = a * a % denom;
  }
  return res;
}
int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(0), cin.tie(0);
  long long t;
  cin >> t;
  while (t-- > 0) {
    long long n;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    vector<pair<long long, long long>> a(n), b(n);
    for (long long i = (0); i < (n); i++) {
      cin >> a[i].first;
      a[i].second = i;
      v[i].first = a[i].first;
    }
    for (long long i = (0); i < (n); i++) {
      cin >> b[i].first;
      b[i].second = i;
      v[i].second = b[i].first;
    }
    sort((a).begin(), (a).end());
    sort((b).begin(), (b).end());
    vector<bool> vis_a(n, false);
    vector<bool> vis_b(n, false);
    long long a_idx = n - 1;
    vector<bool> res(n, false);
    while (true) {
      long long min_b_val = INT_MAX;
      for (long long i = a_idx; i < n; i++) {
        if (vis_a[i]) break;
        min_b_val = min(v[a[i].second].second, min_b_val);
        res[a[i].second] = true;
        vis_a[i] = true;
      }
      if (min_b_val == INT_MAX) break;
      pair<long long, long long> p = {min_b_val - 1, INT_MAX};
      auto it = lower_bound(b.begin(), b.end(), p);
      long long b_idx = it - b.begin();
      long long min_a_val = INT_MAX;
      for (long long i = b_idx; i < n; i++) {
        if (vis_b[i]) break;
        min_a_val = min(min_a_val, v[b[i].second].first);
        res[b[i].second] = true;
        vis_b[i] = true;
      }
      p = {min_a_val - 1, INT_MAX};
      a_idx = lower_bound(a.begin(), a.end(), p) - a.begin();
    }
    for (long long i = (0); i < (n); i++) cout << (res[i] ? "1" : "0");
    cout << endl;
  }
  return 0;
}
