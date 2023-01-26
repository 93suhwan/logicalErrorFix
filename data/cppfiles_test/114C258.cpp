#include <bits/stdc++.h>
using namespace std;
template <class val>
inline val gcd(val a, val b) {
  return (a ? gcd(b % a, a) : b);
}
template <class val>
inline val fmul(val a, val b, val m) {
  if (!b) return 0;
  if (!(b - 1)) return a;
  if (b % 2)
    return (fmul(a, b / 2, m) * 2 + a) % m;
  else
    return (fmul(a, b / 2, m) * 2) % m;
}
template <class val>
inline bool getBit(val pos, val mask) {
  return ((mask >> pos) & 1);
}
void fastio() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
}
void init() {
  freopen(
      "test"
      ".inp",
      "r", stdin);
  freopen(
      "test"
      ".out",
      "w", stdout);
}
const int N = int(1e6) + 1;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 10], minn = 1e10;
    for (int i = 1; i <= n; i++) cin >> a[i], minn = min(minn, a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n / 2; i++) cout << a[i + 1] << " " << a[1] << '\n';
  }
  return 0;
}
