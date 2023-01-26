#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const long long INF64 = 0x3f3f3f3f3f3f3f3f;
const long long INF32 = 0x3f3f3f3f;
const long long MOD = 1000000007;
void solve() {
  long long n;
  string s;
  cin >> n;
  cin >> s;
  long long k = 0;
  for (; k < n && s[k] == '1'; k++)
    ;
  if (k == n) {
    n -= n % 2;
    cout << 1 << ' ' << n / 2 << ' ' << n / 2 + 1 << ' ' << n << '\n';
  } else {
    if (k < n / 2) {
      cout << k + 1 << ' ' << n << ' ' << k + 2 << ' ' << n << '\n';
    } else {
      cout << 1 << ' ' << k + 1 << ' ' << 1 << ' ' << k << '\n';
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) solve();
}
