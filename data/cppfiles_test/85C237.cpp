#include <bits/stdc++.h>
using namespace std;
long long power(long long N, long long M) {
  long long power = N, sum = 1;
  if (N == 0) sum = 0;
  while (M > 0) {
    if ((M & 1) == 1) {
      sum *= power;
    }
    power = power * power;
    M = M >> 1;
  }
  return sum;
}
void solve() {
  string s;
  cin >> s;
  long long n = s.length();
  vector<long long> m;
  for (long long i = 1; i < n; i++) {
    if (s[i] == s[i - 1])
      continue;
    else {
      if (s[i] == '1')
        m.push_back(0);
      else
        m.push_back(1);
    }
  }
  if (s[n - 1] == '0') m.push_back(0);
  if (s[n - 1] == '1') m.push_back(1);
  long long x = count(m.begin(), m.end(), 0);
  if (x == 0) cout << 0 << "\n";
  if (x == 1) cout << 1 << "\n";
  if (x >= 2) cout << 2 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
