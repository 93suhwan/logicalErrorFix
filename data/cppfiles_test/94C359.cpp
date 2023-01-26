#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long n = s.size();
  string a, b;
  for (long long i = 0; i < n; ++i) {
    if (i % 2 == 0)
      a.push_back(s[i]);
    else
      b.push_back(s[i]);
  }
  if (!b.size()) b.push_back('0');
  long long p = stoi(a), q = stoi(b);
  cout << (p + 1) * (q + 1) - 2 << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; ++i) solve();
  return 0;
}
