#include <bits/stdc++.h>
using namespace std;
long long IOS = []() {
  ios::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();
template <class T>
void _W(const T &x) {
  cout << x;
}
template <class T>
void _W(T &x) {
  cout << x;
}
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++)) cout << ' ';
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  cout << ", ";
  W(tail...);
}
using pii = pair<long long, long long>;
const long long N = 1e6 + 10, mod = 998244353;
inline long long quick(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
namespace lukas {
long long qmi(long long a, long long k, long long p) {
  long long res = 1 % p;
  while (k) {
    if (k & 1) res = (long long)res * a % p;
    a = (long long)a * a % p;
    k >>= 1;
  }
  return res;
}
long long C(long long a, long long b, long long p) {
  if (a < b) return 0;
  long long x = 1, y = 1;
  for (long long i = a, j = 1; j <= b; i--, j++) {
    x = (long long)x * i % p;
    y = (long long)y * j % p;
  }
  return x * (long long)qmi(y, p - 2, p) % p;
}
long long lucas(long long a, long long b, long long p) {
  if (a < p && b < p) return C(a, b, p);
  return (long long)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}
}  // namespace lukas
long long dp[N], n, k, ans;
long long idx;
long long l, r, ans1, ans2;
long long calc(long long l, long long r) { return dp[r] - dp[l] - 1; }
void solve() {
  cin >> n >> k;
  string s;
  cin >> s;
  s = " " + s;
  for (long long i = 1; i <= n; i++)
    if (s[i] != '0') dp[++idx] = i;
  dp[idx + 1] = n + 1;
  if (!k || idx < k) return cout << 1, void(0);
  l = 1, r = k;
  ans1 = calc(l - 1, r + 1);
  ans = (ans + lukas::lucas(ans1, k, mod)) % mod;
  l++, r++;
  for (; r <= idx;) {
    ans1 = calc(l - 1, r + 1);
    ans2 = calc(l - 1, r);
    ans = (((ans + lukas::lucas(ans1, k, mod)) % mod -
            lukas::lucas(ans2, k - 1, mod)) +
           mod) %
          mod;
    l++, r++;
  }
  ans %= mod;
  return cout << ans, void(0);
}
signed main() {
  long long tt = 1;
  while (tt--) {
    solve();
  }
}
