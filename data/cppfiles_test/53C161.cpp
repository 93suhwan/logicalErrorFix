#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 200005;
long long fasmul(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b / 2;
  }
  return res;
}
void solve() {
  long long n;
  char c;
  string s;
  cin >> n >> c >> s;
  long long d = n / 2;
  long long ok = 1;
  for (long long i = 0; i < n; i++)
    if (s[i] != c) ok = 0;
  if (ok) {
    cout << 0 << "\n";
    return;
  }
  for (long long i = d; i < n; i++) {
    if (s[i] == c) {
      cout << 1 << "\n";
      cout << i + 1 << "\n";
      return;
    }
  }
  cout << 2 << "\n";
  cout << n << " " << n - 1 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
