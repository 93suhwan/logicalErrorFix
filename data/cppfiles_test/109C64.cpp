#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void c_a_r() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long turn20(string s, long long n) {
  long long f = 0, ans = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0')
      f++;
    else {
    }
  }
  if (f == n) {
    return 0;
  }
  if (s[n - 1] != '0') ans += s[n - 1] - '0';
  for (long long i = 0; i < n - 1; i++) {
    if (s[i] != '0') {
      ans += s[i] - '0' + 1;
    }
  }
  return ans;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  cout << turn20(s, n) << endl;
}
int32_t main() {
  c_a_r();
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
