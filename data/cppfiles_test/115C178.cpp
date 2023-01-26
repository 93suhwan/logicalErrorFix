#include <bits/stdc++.h>
#pragma GCC Optimize("Ofast")
using namespace std;
bool check(long long n, uint64_t h, uint64_t k, const vector<long long>& a) {
  vector<long long> pref(n + 1);
  uint64_t cnt = k;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] + k >= a[i + 1]) {
      cnt += a[i + 1] - a[i];
    } else {
      cnt += k;
    }
    if (cnt >= h) return true;
  }
  return false;
}
void solve() {
  long long n, h;
  cin >> n >> h;
  vector<long long> a(n);
  for (int i_ = 0; i_ < a.size(); i_++) cin >> a[i_];
  long long l = 0, r = h;
  while (l + 1 < r) {
    long long m = (r + l) / 2;
    if (check(n, h, m, a)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t_;
  cin >> t_;
  while (t_--) solve();
  return 0;
}
