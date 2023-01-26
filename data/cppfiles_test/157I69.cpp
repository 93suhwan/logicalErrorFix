#include <bits/stdc++.h>
using namespace std;
template <typename T>
void rd(T& x) {
  int f = 0, c;
  while (!isdigit(c = getchar())) f ^= !(c ^ 45);
  x = (c & 15);
  while (isdigit(c = getchar())) x = x * 10 + (c & 15);
  if (f) x = -x;
}
template <typename T>
void pt(T x, int c = 10) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) pt(x / 10, -1);
  putchar(x % 10 + 48);
  if (c != -1) putchar(c);
}
template <typename T>
void umax(T& x, const T& y) {
  if (x < y) x = y;
}
template <typename T>
void umin(T& x, const T& y) {
  if (x > y) x = y;
}
using vi = vector<int>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long, long>;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n, k;
string s;
ll jc[maxn], inv[maxn];
ll qp(ll a, ll b) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return ans;
}
ll calc(ll x, ll y) { return jc[x] * inv[y] % mod * inv[x - y] % mod; }
int sum[maxn];
int main() {
  cin >> n >> k >> s;
  if (k == 0) {
    cout << 1 << "\n";
    return 0;
  }
  jc[0] = 1;
  for (int i = 1; i <= n; i++) jc[i] = jc[i - 1] * i % mod;
  inv[n] = qp(jc[n], mod - 2);
  for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  for (int i = 0; i < n; i++)
    sum[i] = (s[i] == '1') + (i >= 1 ? sum[i - 1] : 0);
  ll ans = 1;
  int cnt = 0;
  for (int i = 0, j = 0; i < n; i++) {
    if (s[i] == '0') {
      if (cnt < k) continue;
      ans += calc(i - j, k - 1);
    } else {
      cnt++;
      while (cnt > k) cnt -= s[j++] == '1';
      if (cnt == k)
        ans += calc(i - j + 1, k) -
               calc(i - j, sum[i - 1] - (j >= 1 ? sum[j - 1] : 0));
    }
  }
  cout << (ans % mod + mod) % mod << "\n";
  return 0;
}
