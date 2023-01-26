#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2.5e5 + 5, P = 998244353;
int n, d[N], lim, bit, rev[1 << 18];
ll Pow(ll a, int n, ll r = 1) {
  for (; n; n >>= 1, a = a * a % P)
    if (n & 1) r = r * a % P;
  return r;
}
void NTT(vector<ll>& a, int t) {
  if (t) reverse(a.begin() + 1, a.end());
  for (int i = (0), ie = (lim); i < ie; i++)
    if (rev[i] < i) swap(a[i], a[rev[i]]);
  for (int i = 1; i < lim; i <<= 1) {
    ll wn = Pow(3, P / 2 / i);
    for (int j = 0; j < lim; j += i << 1) {
      ll w = 1;
      for (int k = (j), ke = (j + i); k < ke; k++) {
        ll &x = a[k], y = a[k + i] * w % P;
        a[k + i] = (x - y) % P, (x += y) %= P, w = w * wn % P;
      }
    }
  }
  ll inv = Pow(lim, P - 2);
  if (t)
    for (int i = (0), ie = (lim); i < ie; i++) (a[i] *= inv) %= P;
}
vector<ll> solve(int l, int r) {
  if (l == r) {
    vector<ll> res(2);
    res[0] = 1, res[1] = d[l];
    return res;
  }
  int mid = l + r >> 1;
  auto &&L = solve(l, mid), &&R = solve(mid + 1, r);
  for (lim = 1, bit = -1; lim <= r - l + 1; lim <<= 1, bit++)
    ;
  for (int i = (1), ie = (lim); i < ie; i++)
    rev[i] = rev[i >> 1] >> 1 | (i & 1) << bit;
  L.resize(lim), R.resize(lim);
  NTT(L, 0), NTT(R, 0);
  for (int i = (0), ie = (lim); i < ie; i++) (L[i] *= R[i]) %= P;
  NTT(L, 1);
  return L;
}
int main() {
  cin >> n;
  int u, v;
  for (int i = (2); i <= (n); i++)
    d[i]--, scanf("%d%d", &u, &v), d[u]++, d[v]++;
  auto&& res = solve(1, n);
  ll ans = 0, fac = 1;
  for (int i = (1); i <= (n); i++)
    (fac *= i) %= P, (ans += (n - i & 1 ? -1 : 1) * fac * res[n - i]) %= P;
  cout << (ans + P) % P;
}
