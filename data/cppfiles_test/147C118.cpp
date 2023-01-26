#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long a, long long b) {
  if (b == 1) return a;
  if (b == 0) return 1;
  long long ans = power(a, b / 2);
  ans = (ans * ans);
  if (b & 1) ans = (ans * a);
  return ans;
}
long long N = 5000010;
void solve() {
  string s;
  cin >> s;
  long long n = s.size();
  long long cnte, cntn;
  cnte = cntn = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'N')
      cntn++;
    else
      cnte++;
  }
  if ((cntn == 1 && cnte == n - 1)) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
