#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long n) {
  if (n == 0)
    return 1;
  else if (n == 1)
    return x;
  else if (n % 2)
    return (x * power((x * x), n / 2));
  else
    return (power((x * x), n / 2));
}
long long logab(long long n, long long base) {
  return (n > base - 1) ? 1 + logab(n / base, base) : 0;
}
void solve() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  ;
  long long n;
  string s;
  cin >> s;
  string w;
  cin >> w;
  long long x, ans = 0;
  long long y = s.find(w[0]);
  for (long long i = 1; i < w.length(); i++) {
    x = s.find(w[i]);
    ans += abs(y - x);
    y = x;
  }
  cout << ans << endl;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
