#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1), EPS = 1e-8;
const int inf = 1 << 29, Mod = 1e9 + 7, P = 998244353;
int64_t ts = 1, _ts = 1, n, M;
const int64_t INF = 1ll << 59;
int64_t qpow(int64_t a, int64_t b, int64_t mod = Mod, int64_t s = 1) {
  for (; b; b >>= 1, a = (a * a) % mod)
    if (b & 1) s = (s * a) % mod % mod;
  return s;
};
int64_t gcd(int64_t a, int64_t b) { return (b ? gcd(b, a % b) : a); };
int64_t lcm(int64_t a, int64_t b) { return a * b / gcd(a, b); };
pair<int64_t, int64_t> EXgcd(int64_t x, int64_t y) {
  if (!y) {
    return {1, 0};
  }
  pair<int64_t, int64_t> a = EXgcd(y, (x + y) % y);
  return {a.second, a.first - a.second * (x / y)};
};
int64_t Inv(int64_t x, int64_t m) { return (EXgcd(x, m).first + m) % m; };
void yesno(bool ok, bool upper) {
  if (ok)
    cout << (upper ? "YES\n" : "Yes\n");
  else
    cout << (upper ? "NO\n" : "No\n");
};
bool maskq(int64_t mk, int b) { return ((mk >> b) & 1); };
int64_t maskch(int64_t mk, int b) { return (mk ^ (1ll << b)); };
bool isdiv(int64_t x, int64_t b) { return !(x % b); };
template <class T>
void Get(T& x) {
  x = 0;
  short f = 1;
  char c;
  while (!isdigit(c = getchar()))
    if (c == '-') f = -1;
  do x = x * 10 + c - '0';
  while (isdigit(c = getchar()));
  x *= f;
}
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> ts;
  for (; _ts++ <= ts;) {
    cin >> n;
    string s;
    cin >> s;
    int ans = n + 1;
    for (int i = 0; i < 26; ++i) {
      bool ok = 1;
      int cnt = 0;
      int l = 0, r = n - 1;
      for (; l < r;) {
        if (s[l] != i + 'a' && s[r] != i + 'a') {
          if (s[l] != s[r]) {
            ok = 0;
            break;
          } else
            ++l, --r;
        } else if (s[l] == s[r]) {
          if (s[l] == i + 'a') cnt += 2;
          ++l, --r;
        } else if (s[l] == i + 'a')
          ++l, ++cnt;
        else if (s[r] == i + 'a')
          --r, ++cnt;
      }
      if (!ok || !cnt) continue;
      if (s[l] == s[r] && l == r && s[l] == i + 'a') cnt--;
      --l, ++r;
      for (; l >= 0 && r < n;) {
        if (s[l] == s[r]) {
          if (s[l] == 'a' + i) cnt -= 2;
          --l, ++r;
        } else if (s[l] == 'a' + i)
          --l;
        else if (s[r] == 'a' + i)
          ++r;
      }
      ans = min(ans, cnt);
    }
    if (ans > n)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }
}
