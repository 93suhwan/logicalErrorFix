#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long long long min(long long long long a, long long long long b) {
  return (a > b) ? b : a;
}
long long long long max(long long long long a, long long long long b) {
  return (a > b) ? a : b;
}
void solve() {
  string s;
  cin >> s;
  set<char> se;
  long long n = s.size(), r = 0, g = 0;
  for (long long i = 0; i < (n); i++) {
    se.insert(s[i]);
  }
  cout << min(n / 2, se.size()) << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tcs;
  cin >> tcs;
  for (long long i = 0; i < (tcs); i++) solve();
  ;
  return 0;
}
