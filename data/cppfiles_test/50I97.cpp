#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 10;
const long long mod = 998244353;
const long long oo = 1e9;
long long seg[40 * maxn], L[40 * maxn], R[40 * maxn];
long long la1[40 * maxn], la2[40 * maxn];
long long cnt = 1;
void down(long long id, long long l, long long r) {
  long long mid = (l + r) >> 1;
  long long t = la2[id];
  long long m = la1[id];
  la1[L[id]] *= m;
  la1[R[id]] *= m;
  la2[L[id]] *= m;
  la2[R[id]] *= m;
  seg[L[id]] *= m;
  seg[L[id]] = seg[L[id]];
  seg[R[id]] *= m;
  seg[R[id]] = seg[R[id]];
  la2[L[id]] = (la2[L[id]] + t) % mod;
  la2[R[id]] = (la2[R[id]] + t) % mod;
  seg[L[id]] = (seg[L[id]] + (t * (mid - l + 1)) % mod) % mod;
  seg[R[id]] = (seg[R[id]] + (t * (r - mid)) % mod) % mod;
  la1[id] = 1;
  la2[id] = 0;
}
void upd(long long u, long long v, long long val, long long type,
         long long l = 1, long long r = oo, long long id = 1) {
  if (l > v || r < u) return;
  if (l >= u && r <= v) {
    if (!type) {
      (seg[id] *= val) %= mod;
      (la1[id] *= val) %= mod;
      (la2[id] *= val) %= mod;
    } else {
      (seg[id] += (val * (r - l + 1)) % mod) %= mod;
      (la2[id] += val) %= mod;
    }
    return;
  }
  if (!L[id]) L[id] = ++cnt;
  if (!R[id]) R[id] = ++cnt;
  down(id, l, r);
  long long mid = (l + r) >> 1;
  upd(u, v, val, type, l, mid, L[id]);
  upd(u, v, val, type, mid + 1, r, R[id]);
  seg[id] = (seg[L[id]] + seg[R[id]]) % mod;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, x;
  cin >> n >> x;
  upd(1, x, 1, 1);
  for (long long i = 2; i <= n; i++) {
    cin >> x;
    long long s = seg[1];
    upd(1, x, -1, 0);
    upd(1, x, s, 1);
    upd(x + 1, oo, 0, 0);
  }
  cout << seg[1];
}
