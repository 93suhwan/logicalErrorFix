#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, a, b;
  cin >> n >> a >> b;
  if (abs(a - b) > 1) {
    cout << -1 << '\n';
    return;
  }
  if (a + b > n - 2) {
    cout << -1 << '\n';
    return;
  }
  long long c = 0;
  long long d = n - 1;
  vector<long long> res;
  if (a >= b) {
    res = {0};
    c++;
    while (a || b) {
      if (a > 0) {
        res.push_back(d);
        a--;
        d--;
      }
      if (b > 0) {
        res.push_back(c);
        b--;
        c++;
      }
    }
  } else {
    res = {n - 1};
    d--;
    while (a || b) {
      if (b > 0) {
        res.push_back(c);
        b--;
        c++;
      }
      if (a > 0) {
        res.push_back(d);
        a--;
        d--;
      }
    }
  }
  if (res.back() == c - 1) {
    for (long long j = c; j <= d; j++) res.push_back(j);
  } else {
    for (long long j = d; j >= c; j--) res.push_back(j);
  }
  for (long long x : res) cout << (x + 1) << ' ';
  cout << '\n';
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
