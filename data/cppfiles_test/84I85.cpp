#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,tune=native")
template <typename T>
void print(T&& x) {
  cout << x << "\n";
}
template <typename T, typename... S>
void print(T&& x, S&&... y) {
  cout << x << ' ';
  print(y...);
}
struct segment_tree {
  vector<long long> val, tag;
  long long type;
  inline long long mid(long long l, long long r) { return l + r >> 1; }
  segment_tree(long long _siz, long long _type) {
    val.resize(4 * _siz), tag.resize(4 * _siz), type = _type;
  }
  inline long long oper(long long i, long long j) {
    if (type == 0)
      return i + j;
    else if (type == 1)
      return min(i, j);
    else
      return max(i, j);
  }
  inline long long def() {
    if (type == 0)
      return 0;
    else if (type == 1)
      return 4000000000000000000;
    else
      return -4000000000000000000;
  }
  void pull(long long k) { val[k] = oper(val[k << 1], val[(k << 1) + 1]); }
  void push(long long k, long long l, long long r) {
    if (l != r) {
      if (type) {
        tag[k << 1] += tag[k];
        tag[(k << 1) + 1] += tag[k];
        val[k << 1] += tag[k];
        val[(k << 1) + 1] += tag[k];
      } else {
        tag[k << 1] += tag[k];
        tag[(k << 1) + 1] += tag[k];
        val[k << 1] += (mid(l, r) - l + 1) * tag[k];
        val[(k << 1) + 1] += (r - mid(l, r)) * tag[k];
      }
    }
    tag[k] = 0;
  }
  void modify(long long k, long long l, long long r, long long ql, long long qr,
              long long x) {
    if (l > qr || r < ql) return;
    if (ql <= l && qr >= r) {
      if (type)
        val[k] += x;
      else
        val[k] += (r - l + 1) * x;
      tag[k] += x;
      return;
    }
    push(k, l, r);
    modify(k << 1, l, mid(l, r), ql, qr, x);
    modify((k << 1) + 1, mid(l, r) + 1, r, ql, qr, x);
    pull(k);
  }
  long long query(long long k, long long l, long long r, long long ql,
                  long long qr) {
    if (l > qr || r < ql) return def();
    if (ql <= l && qr >= r) return val[k];
    push(k, l, r);
    return oper(query(k << 1, l, mid(l, r), ql, qr),
                query((k << 1) + 1, mid(l, r) + 1, r, ql, qr));
  }
};
template <long long maxn>
struct NT {
  vector<long long> pr;
  long long lpd[maxn];
  NT() {
    pr.clear();
    for (long long i = (0); i < ((long long)(maxn)); i++) lpd[i] = -1;
    for (long long i = (2); i < ((long long)(maxn)); i++) {
      if (lpd[i] == -1) lpd[i] = i, pr.push_back(i);
      for (auto p : pr) {
        if (p * i >= maxn) break;
        lpd[p * i] = p;
        if (i % p == 0) break;
      }
    }
  }
  inline bool isp(long long x) { return lpd[x] == x; }
  signed fac_cnt(signed x) {
    assert(x >= 1 && x < maxn);
    signed res = 1, lst = 0, cur = 0;
    while (x > 1) {
      signed p = lpd[x];
      if (p != lst) res *= cur + 1, cur = 0;
      cur++;
      lst = p;
      x /= p;
    }
    return res * (cur + 1);
  }
};
const long long Mod = 1000000007, Mod2 = 998244353;
const long long MOD = Mod;
const long long maxn = 100005, maxm = 17, maxk = 30;
long long dp[maxm][maxn], phi[maxn], cnt[maxk + 5][maxn];
NT<maxn> nt;
vector<long long> factors[maxn];
void orzck() {
  for (long long i = (1); i < ((long long)(maxn)); i++)
    dp[1][i] = 1ll * i * (i - 1) / 2;
  for (long long i = (1); i < ((long long)(maxn)); i++) {
    vector<long long> vec;
    long long x = i;
    while (x > 1) {
      vec.push_back(nt.lpd[x]);
      x /= nt.lpd[x];
    }
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    phi[i] = i;
    for (auto p : vec) phi[i] /= p, phi[i] *= p - 1;
  }
  for (long long i = (2); i < ((long long)(maxn)); i++)
    for (long long j = i * 2; j < maxn; j += i) factors[j].push_back(i);
  for (long long i = (2); i < ((long long)(maxn)); i++)
    reverse(factors[i].begin(), factors[i].end());
  for (long long i = (1); i < ((long long)(maxk + 1)); i++) {
    cnt[i][i] = 0;
    for (long long j = (i + 1); j < ((long long)(maxn)); j++) {
      cnt[i][j] = cnt[i][j - 1];
      for (auto x : factors[j]) {
        if (x >= i)
          cnt[i][j] += phi[j / x];
        else
          break;
      }
    }
  }
  for (long long i = (1); i < ((long long)(maxm - 2)); i++) {
    segment_tree tree(maxn, 1);
    for (long long j = (1); j < ((long long)(maxn - 2)); j++)
      dp[i + 1][j] = 4000000000000000000;
    for (long long j = (1); j < ((long long)(maxk)); j++)
      for (long long k = (j + 1); k < ((long long)(maxn - 2)); k++)
        (dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + cnt[j + 1][k]));
    for (long long j = (1); j < ((long long)(maxk)); j++)
      tree.modify(1, 1, maxn - 3, j, j, 4000000000000000000);
    for (long long j = (maxk); j < ((long long)(maxn - 2)); j++)
      tree.modify(1, 1, maxn - 3, j, j, dp[i][j]);
    for (long long j = (maxk); j < ((long long)(maxn - 2)); j++) {
      for (auto x : factors[j]) {
        if (x >= maxk)
          tree.modify(1, 1, maxn - 3, 1, x - 1, phi[j / x]);
        else
          break;
      }
      (dp[i + 1][j] = min(dp[i + 1][j], tree.query(1, 1, maxn - 3, 1, j - 1)));
    }
  }
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n, k;
    cin >> n >> k;
    if (k >= maxm)
      print(n);
    else
      print(n + dp[k][n]);
  }
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cout << fixed << setprecision(15);
  long long t;
  t = 1;
  while (t--) orzck();
  return 0;
}
