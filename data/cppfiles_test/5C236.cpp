#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void pn(T... args) {
  ((cout << args << " "), ...);
  cout << "\n";
}
template <typename... T>
void ps(T... args) {
  ((cout << args << " "), ...);
  cout << "";
}
long long power(long long a, long long b, long long P = 1000000007) {
  long long res = 1;
  for (; b; b >>= 1, a = 1ll * a * a % P)
    if (b & 1) res = 1ll * res * a % P;
  return res;
}
void solve() {
  long long n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  a = '0' + a + '0';
  b = '0' + b + '0';
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    if (a[i] == '0') {
      if (b[i] == '1') ans++, b[i] = 0;
    } else if (a[i] == '1') {
      if (b[i - 1] == '1')
        ans++, b[i - 1] = 0;
      else if (b[i + 1] == '1')
        ans++, b[i + 1] = 0;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
