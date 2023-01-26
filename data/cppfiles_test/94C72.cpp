#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  long long n;
  cin >> n;
  long long odd = 0, even = 0;
  string s = to_string(n);
  for (int i = 0; i < s.size(); i++) {
    long long d = s[i] - '0';
    if (i % 2 == 0) {
      even = (even * 10) + d;
    } else {
      odd = (odd * 10) + d;
    }
  }
  long long ans = ((even + 1) * (odd + 1)) - 2;
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
