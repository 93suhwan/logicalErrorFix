#include <bits/stdc++.h>
using namespace std;
using ul = unsigned long long;
using ll = long long;
using db = double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;
using vp = vector<pii>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;
const ll MOD = 1e9 + 7;
inline ll add(ll x, ll y) { return (x + y) % MOD; }
inline ll mul(ll x, ll y) { return (x * y) % MOD; }
ll T, N, M, r, c, r_, c_, p;
vector<vector<vi>> V;
ll inv(ll a) {
  ll ans = 1, b = a, e = MOD - 2;
  while (e) {
    if (e & 1ll) ans = mul(ans, b);
    e >>= 1ll, b = mul(b, b);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> N >> M >> r >> c >> r_ >> c_ >> p;
    r--, c--, r_--, c_--;
    V.assign(N, vector<vi>(M, vi(4, 0)));
    ll n = mul((100ll - p), inv(100));
    ll y = mul(p, inv(100));
    ll a = 0, n_ = 1, s = 0, i = r, j = c, d = 0;
    if (i == 0) {
      if (d == 2)
        d = 1;
      else if (d == 3)
        d = 0;
    } else if (i == N - 1) {
      if (d == 0)
        d = 3;
      else if (d == 1)
        d = 2;
    }
    if (j == 0) {
      if (d == 2)
        d = 3;
      else if (d == 1)
        d = 0;
    } else if (j == M - 1) {
      if (d == 3)
        d = 2;
      else if (d == 0)
        d = 1;
    }
    while (V[i][j][d] == 0) {
      V[i][j][d] = 1;
      if (i == r_ || j == c_) {
        a = add(a, mul(n_, s));
        n_ = mul(n_, n);
      }
      if (d == 0) i++, j++;
      if (d == 1) i++, j--;
      if (d == 2) i--, j--;
      if (d == 3) i--, j++;
      if (i == 0) {
        if (d == 2)
          d = 1;
        else if (d == 3)
          d = 0;
      } else if (i == N - 1) {
        if (d == 0)
          d = 3;
        else if (d == 1)
          d = 2;
      }
      if (j == 0) {
        if (d == 2)
          d = 3;
        else if (d == 1)
          d = 0;
      } else if (j == M - 1) {
        if (d == 3)
          d = 2;
        else if (d == 0)
          d = 1;
      }
      s++;
    }
    a = mul(y, a);
    ll E = mul(add(a, mul(n_, s)), inv(add(1, MOD - n_)));
    cout << E << '\n';
  }
}
