#include <bits/stdc++.h>
using namespace std;
long long ceil(long long a, long long b) { return (a + b - 1) / b; }
long long expo(long long a, long long b, long long mod) {
  long long r = 1;
  while (b > 0) {
    if (b & 1) r = (r * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return r;
}
void solve() {
  int n;
  cin >> n;
  vector<string> s(n - 2);
  for (int i = 0; i < n - 2; i++) {
    cin >> s[i];
  }
  string ans;
  ans += s[0];
  for (int i = 1; i < n - 2; i++) {
    if (s[i][0] == s[i - 1][1]) {
      ans += s[i][1];
    } else {
      ans += s[i];
    }
  }
  while (ans.size() != n) {
    ans += "a";
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    solve();
  }
}
