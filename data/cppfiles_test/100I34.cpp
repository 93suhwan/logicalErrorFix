#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 1e5 + 5;
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-9;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (auto &i : v) {
    cin >> i;
  }
  sort(v.begin(), v.end());
  if (n == 1)
    cout << v[0] << "\n";
  else {
    long long sum = 0;
    long long mx = INT_MIN;
    for (long long i = 1; i < n; i++) {
      sum += v[i] - (sum + v[i - 1]);
      mx = max(mx, sum);
    }
    cout << mx << "\n";
  }
}
int32_t main() {
  long long tc = 1;
  cin >> tc;
  for (long long t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}
