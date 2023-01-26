#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
class NTT {
  long long mod;
  int rootOrder;
  long long root;
  vector<long long> pw;
  vector<vector<long long> > ca;
  vector<int> rv;
  long long qpowmod(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
      if (b & 1) res = res * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return res;
  }
  int rev(int num, int blen) {
    int res = 0;
    for (int i = 0; i < blen; i++) {
      if (num & 1) res |= 1 << (blen - i - 1);
      num >>= 1;
    }
    return res;
  }
  long long get_generator() {
    vector<long long> fact;
    long long phi = mod - 1;
    long long t = mod - 1;
    for (long long i = 2; i * i <= t; i++)
      if (t % i == 0) {
        fact.push_back(i);
        while (t % i == 0) t /= i;
      }
    if (t) fact.push_back(t);
    for (int i = 2;; i++) {
      bool ok = true;
      for (long long j : fact)
        if (qpowmod(i, phi / j, mod) == 1) {
          ok = false;
          break;
        }
      if (ok) return i;
    }
    throw;
  }
  void init_rv(int n) {
    int blen = 0;
    while ((1 << blen) < n) blen++;
    int len = 1 << blen;
    if (rv.size() != len) {
      rv.resize(len);
      for (int i = 0; i < len; i++) rv[i] = rev(i, blen);
    }
  }

 public:
  NTT(long long mod, int maxlen) : mod(mod) {
    rootOrder = 0;
    while ((1 << rootOrder) < maxlen) rootOrder++;
    long long k = 1LL << rootOrder;
    assert((mod - 1) % k == 0);
    long long g = get_generator();
    root = qpowmod(g, (mod - 1) / k, mod);
    pw.resize(rootOrder + 1);
    pw[rootOrder] = root;
    for (int i = rootOrder - 1; i >= 0; i--)
      pw[i] = pw[i + 1] * pw[i + 1] % mod;
    ca.resize(rootOrder);
    for (int i = 1; i <= rootOrder; i++) {
      int cur2 = 1 << (i - 1);
      int cur = 1 << (i);
      long long cn = pw[i];
      long long c = 1;
      ca[i - 1].resize(cur2);
      for (int k = 0; k < cur2; k++) {
        ca[i - 1][k] = c;
        c = c * cn % MOD;
      }
    }
  }
  void transformInPlace(bool inverse, long long* p, int len) {
    assert((len & (len - 1)) == 0);
    init_rv(len);
    int blen = 0;
    while ((1 << blen) < len) blen++;
    for (int i = 0; i < len; i++) {
      int id = rv[i];
      if (id < i) swap(p[i], p[id]);
    }
    for (int i = 1; i <= blen; i++) {
      int cur2 = 1 << (i - 1);
      int cur = 1 << (i);
      for (int j = 0; j < len; j += cur) {
        long long* chunk = &p[j];
        for (int k = 0; k < cur2; k++) {
          long long t = chunk[k + cur2] * ca[i - 1][k] % MOD;
          chunk[k + cur2] = (chunk[k] + (MOD - t));
          if (chunk[k + cur2] > MOD) chunk[k + cur2] -= MOD;
          chunk[k] = (chunk[k] + t);
          if (chunk[k] > MOD) chunk[k] -= MOD;
        }
      }
    }
    if (inverse) {
      reverse(p + 1, p + len);
      long long mul = qpowmod(len, mod - 2, mod);
      for (int i = 0; i < len; i++) p[i] = p[i] * mul % mod;
    }
  }
  vector<long long> transform(bool inverse, vector<long long> v) {
    assert((v.size() & (v.size() - 1)) == 0);
    transformInPlace(inverse, &v[0], v.size());
    return v;
  }
};
const int MAXN = 100000;
char buf[MAXN][5];
int cnt[2][3][2];
long long dp2[MAXN + 1][2][2];
bool fits(char* s, char* t) {
  for (int i = 0; i < 2; i++)
    if (s[i] != '?' && s[i] != t[i]) return false;
  return true;
}
vector<long long>& operator*=(vector<long long>& a,
                              const vector<long long>& b) {
  assert(a.size() == b.size());
  for (int i = 0; i < a.size(); i++) a[i] = (a[i] * b[i]) % MOD;
  return a;
}
vector<long long> ONE;
vector<long long> qpolypow(vector<long long> a, long long pw, NTT& ntt) {
  vector<long long> res = ONE;
  while (pw) {
    if (pw & 1) res *= a;
    a *= a;
    pw /= 2;
  }
  return res;
}
vector<long long> poly[3];
int main() {
  int n;
  scanf("%d", &n);
  int sz = 1;
  while (sz < 2 * n + 1 || sz < 4) sz *= 2;
  NTT ntt(MOD, sz);
  for (int i = 0; i < n; i++) {
    scanf("%s", buf[i]);
    int coeff[3] = {};
    if (fits(buf[i], "BB")) coeff[0]++;
    if (fits(buf[i], "BW")) coeff[1]++;
    if (fits(buf[i], "WB")) coeff[1]++;
    if (fits(buf[i], "WW")) coeff[2]++;
    cnt[coeff[0]][coeff[1]][coeff[2]]++;
  }
  vector<long long> res(sz);
  res[0] = 1;
  ntt.transformInPlace(false, &res[0], sz);
  ONE = res;
  for (int i = 0; i < 3; i++) {
    poly[i].resize(sz);
    poly[i][i] = 1;
    ntt.transformInPlace(false, &poly[i][0], sz);
  }
  vector<long long> mul(sz);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 2; k++) {
        int iarr[] = {i, j, k};
        for (int i1 = 0; i1 < sz; i1++) {
          mul[i1] = 0;
          for (int j1 = 0; j1 < 3; j1++) mul[i1] += poly[j1][i1] * iarr[j1];
          mul[i1] %= MOD;
        }
        res *= qpolypow(mul, cnt[i][j][k], ntt);
      }
  ntt.transformInPlace(true, &res[0], sz);
  long long rescnt = 0L;
  for (int i = 0; i <= 0; i++) {
    int pos = n + i;
    if (0 <= pos && pos < res.size()) rescnt += res[pos];
  }
  rescnt %= MOD;
  dp2[0][0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) {
        if (fits(buf[i], "BW"))
          dp2[i + 1][1][k] = (dp2[i + 1][1][k] + dp2[i][j][k]) % MOD;
        if (fits(buf[i], "WB"))
          dp2[i + 1][j][1] = (dp2[i + 1][j][1] + dp2[i][j][k]) % MOD;
      }
  rescnt = (rescnt + MOD - dp2[n][1][1]) % MOD;
  printf("%lld\n", rescnt);
}
