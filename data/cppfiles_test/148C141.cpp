#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  if (x == 0) return y;
  return (gcd(y % x, x));
}
string Tolower(string s) {
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}
string Toupper(string s) {
  transform(s.begin(), s.end(), s.begin(), ::toupper);
  return s;
}
void solve() {
  long long t;
  cin >> t;
  while (t--) {
    long long w, h, n, p, q, ans = 0;
    cin >> w >> h;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      if (i == 0)
        cin >> p;
      else
        cin >> q;
    }
    ans = max(ans, h * (q - p));
    cin >> n;
    for (long long i = 0; i < n; i++) {
      if (i == 0)
        cin >> p;
      else
        cin >> q;
    }
    ans = max(ans, h * (q - p));
    cin >> n;
    for (long long i = 0; i < n; i++) {
      if (i == 0)
        cin >> p;
      else
        cin >> q;
    }
    ans = max(ans, w * (q - p));
    cin >> n;
    for (long long i = 0; i < n; i++) {
      if (i == 0)
        cin >> p;
      else
        cin >> q;
    }
    ans = max(ans, w * (q - p));
    cout << ans << "\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
