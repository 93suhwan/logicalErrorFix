#include <bits/stdc++.h>
using namespace std;
long long nxt() {
  long long res = 0;
  cin >> res;
  return res;
}
vector<long long> nxtv(long long n) {
  vector<long long> v((int)n, 0);
  for (int i = 0; i < n; ++i) cin >> v[i];
  return v;
}
vector<int> nxtvi(long long n) {
  vector<int> v((int)n, 0);
  for (int i = 0; i < n; ++i) cin >> v[i];
  return v;
}
int bitcount(unsigned int v) { return __builtin_popcount(v); }
long long MOD = 1000 * 1000 * 1000 + 7;
long long modmul(long long lhs, long long rhs) {
  return (lhs % MOD) * (rhs % MOD) % MOD;
}
long long modmul_unchecked(long long lhs, long long rhs) {
  return lhs * rhs % MOD;
}
long long mod_pow(long long a, long long b, long long mod) {
  assert(b >= 0);
  long long result = 1;
  a = a % mod;
  for (; b; b >>= 1, a = (a * a) % mod) {
    if (b & 1) result = (result * a) % mod;
  }
  return result;
}
long long mod_inverse(long long a, long long mod) {
  return mod_pow(a, mod - 2, mod);
}
long long cnk_mod(long long n, long long k, long long mod) {
  long long res = 1;
  for (; k; --k, --n) res = ((res * n) % mod) * mod_inverse(k, mod) % mod;
  return res;
}
void precalc() {}
long long get_sum(vector<long long>& pref, long long l, long long r) {
  if (l % 2) return pref[r] - pref[l - 1];
  return -1 * (pref[r] - pref[l - 1]);
}
long long exclude(vector<long long>& pref, long long l, long long r,
                  long long p) {
  assert(l <= p && p <= r);
  if ((p - l + 1) % 2 == 1)
    return get_sum(pref, l, p - 1) + get_sum(pref, p + 1, r);
  return get_sum(pref, l, p - 1) - get_sum(pref, p + 1, r);
}
long long find_zero(vector<long long>& pref, long long l, long long r) {
  if (get_sum(pref, l + 1, r) == 0) return l;
  if (get_sum(pref, l, r - 1) == 0) return r;
  bool left = get_sum(pref, l + 1, r) < 0;
  bool right = get_sum(pref, l, r - 1) < 0;
  auto l_orig = l;
  auto r_orig = r;
  while (l < r) {
    auto mid = l + (r - l) / 2;
    if (exclude(pref, l_orig, r_orig, mid) == 0) return mid;
    auto mid_right = exclude(pref, l_orig, r_orig, mid) < 0;
    if (right && mid_right)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return l;
}
void solve() {
  long long n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<long long> v(n, 0);
  for (long long i = 0LL; i < n; ++i) v[i] = s[i] == '+' ? 1 : -1;
  vector<long long> pref(n + 1, 0);
  for (long long i = 1; i <= n; ++i)
    pref[i] = pref[i - 1] + (i % 2 ? 1 : -1) * v[i - 1];
  for (long long zz = 0LL; zz < q; ++zz) {
    long long l, r;
    cin >> l >> r;
    auto sm = get_sum(pref, l, r);
    if (sm == 0) {
      cout << 0 << endl;
      continue;
    }
    if ((r - l + 1) % 2)
      cout << 1 << endl << find_zero(pref, l, r) << endl;
    else
      cout << 2 << endl << l << " " << find_zero(pref, l + 1, r) << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  srand((unsigned int)time(NULL));
  precalc();
  unsigned long long t = 1;
  cin >> t;
  for (; t > 0; --t) solve();
}
