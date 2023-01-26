#include <bits/stdc++.h>
using namespace std;
const int p = 998244353;
long long pow_mod(long long x, long long n) {
  long long s = 1;
  for (; n; n >>= 1, x = x * x % p)
    if (n & 1) s = s * x % p;
  return s;
}
namespace Pol {
inline int add(int a, int b) { return (a += b) >= p ? a -= p : a; }
inline int mul(int a, int b) { return 1ll * a * b % p; }
vector<int> operator-(const int &v, const vector<int> &a) {
  vector<int> res(a);
  for (int i = 0; i < ((int)res.size()); ++i) res[i] = p - res[i];
  res[0] = add(res[0], v);
  return res;
}
vector<int> operator-(const vector<int> &a, const int &v) {
  vector<int> res(a);
  res[0] = add(res[0], p - v);
  return res;
}
vector<int> operator*(const vector<int> &a, const int &v) {
  vector<int> res(a);
  for (int i = 0; i < ((int)res.size()); ++i) res[i] = mul(res[i], v);
  return res;
}
const int N = 4200000;
int P[N];
void init_P(int n) {
  int l = 0;
  while ((1 << l) < n) ++l;
  for (int i = 0; i < n; ++i) P[i] = (P[i >> 1] >> 1) | ((i & 1) << l - 1);
}
void NTT(vector<int> &a, int type) {
  static int w[N];
  long long G = 3, Gi = pow_mod(G, p - 2);
  int n = ((int)a.size());
  for (int i = 0; i < n; ++i)
    if (i < P[i]) swap(a[i], a[P[i]]);
  for (int i = 2, m = 1; i <= n; m = i, i *= 2) {
    long long wn = pow_mod(type > 0 ? G : Gi, (p - 1) / i);
    w[0] = 1;
    for (int j = 1; j < m; ++j) w[j] = wn * w[j - 1] % p;
    for (int j = 0; j < n; j += i)
      for (int k = 0; k < m; ++k) {
        int t1 = a[j + k], t2 = 1ll * a[j + k + m] * w[k] % p;
        a[j + k] = add(t1, t2);
        a[j + k + m] = add(t1, p - t2);
      }
  }
  if (type < 0) {
    int inv = pow_mod(n, p - 2);
    for (int i = 0; i < n; ++i) a[i] = mul(a[i], inv);
  }
}
vector<int> operator*(const vector<int> &A, const vector<int> &B) {
  int n = 1, n1 = ((int)A.size()), n2 = ((int)B.size());
  while (n < n1 + n2 - 1) n <<= 1;
  init_P(n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n1; ++i) a[i] = add(A[i], p);
  for (int i = 0; i < n2; ++i) b[i] = add(B[i], p);
  NTT(a, 1);
  NTT(b, 1);
  for (int i = 0; i < n; ++i) a[i] = mul(a[i], b[i]);
  NTT(a, -1);
  return a;
}
vector<int> Der(const vector<int> &a) {
  vector<int> res(a);
  for (int i = 0; i < ((int)a.size()) - 1; ++i) res[i] = mul(i + 1, res[i + 1]);
  res[((int)a.size()) - 1] = 0;
  return res;
}
vector<int> Int(const vector<int> &a) {
  static int inv[N];
  if (!inv[1]) {
    inv[1] = 1;
    for (int i = 2; i < N; ++i) inv[i] = mul(p - p / i, inv[p % i]);
  }
  vector<int> res(a);
  res.resize(((int)a.size()) + 1);
  for (int i = ((int)a.size()); i; --i) res[i] = mul(res[i - 1], inv[i]);
  res[0] = 0;
  return res;
}
vector<int> Inv(const vector<int> &a) {
  vector<int> res(1, pow_mod(a[0], p - 2));
  int n = 1;
  while (n < ((int)a.size())) n <<= 1;
  for (int k = 2; k <= n; k <<= 1) {
    int L = 2 * k;
    init_P(L);
    vector<int> t(L);
    copy_n(a.begin(), min(k, ((int)a.size())), t.begin());
    t.resize(L);
    res.resize(L);
    NTT(res, 1);
    NTT(t, 1);
    for (int i = 0; i < L; ++i)
      res[i] = mul(res[i], add(2, p - mul(t[i], res[i])));
    NTT(res, -1);
    res.resize(k);
  }
  res.resize(((int)a.size()));
  return res;
}
pair<vector<int>, vector<int> > Divide(const vector<int> &a,
                                       const vector<int> &b) {
  int n = ((int)a.size()), m = ((int)b.size());
  vector<int> t1(a.rbegin(), a.rbegin() + n - m + 1), t2(b.rbegin(), b.rend());
  t2.resize(n - m + 1);
  vector<int> Q = Inv(t2) * t1;
  Q.resize(n - m + 1);
  reverse(Q.begin(), Q.end());
  vector<int> R = Q * b;
  R.resize(m - 1);
  for (int i = 0; i < ((int)R.size()); ++i) R[i] = add(a[i], p - R[i]);
  return make_pair(Q, R);
}
vector<int> Ln(const vector<int> &a) {
  vector<int> res = Int(Der(a) * Inv(a));
  res.resize(((int)a.size()));
  return res;
}
vector<int> Exp(const vector<int> &a) {
  vector<int> res(1, 1);
  int n = 1;
  while (n < ((int)a.size())) n <<= 1;
  for (int k = 2; k <= n; k <<= 1) {
    vector<int> t(res.begin(), res.end());
    t.resize(k);
    t = Ln(t);
    for (int i = 0; i < min(((int)a.size()), k); ++i)
      t[i] = add(a[i], p - t[i]);
    t[0] = add(t[0], 1);
    res = res * t;
    res.resize(k);
  }
  res.resize(((int)a.size()));
  return res;
}
vector<int> Sqrt(const vector<int> &a) {
  vector<int> res(1, 1);
  long long inv2 = pow_mod(2, p - 2);
  int n = 1;
  while (n < ((int)a.size())) n <<= 1;
  for (int k = 2; k <= n; k <<= 1) {
    vector<int> t(res.begin(), res.end()),
        ta(a.begin(), a.begin() + min(((int)a.size()), k));
    t.resize(k);
    t = Inv(t) * ta;
    res.resize(k);
    for (int i = 0; i < k; ++i) res[i] = mul(add(res[i], t[i]), inv2);
  }
  res.resize(((int)a.size()));
  return res;
}
vector<int> Pow(const vector<int> &a, int k) { return Exp(Ln(a) * k); }
vector<int> Pow(const vector<int> &a, int k, int kk) {
  int n = ((int)a.size()), t = n, m, v, inv, powv;
  vector<int> res(n);
  for (int i = n - 1; ~i; --i)
    if (a[i]) t = i, v = a[i];
  if (k && t >= (n + k - 1) / k) return res;
  if (t == n) {
    if (!k) res[0] = 1;
    return res;
  }
  m = n - t * k;
  res.resize(m);
  inv = pow_mod(v, p - 2);
  powv = pow_mod(v, kk);
  for (int i = 0; i < m; ++i) res[i] = mul(a[i + (k > 0) * t], inv);
  res = Exp(Ln(res) * k);
  res.resize(n);
  for (int i = m - 1; ~i; --i) {
    long long tmp = mul(res[i], powv);
    res[i] = 0, res[i + t * k] = tmp;
  }
  return res;
}
}  // namespace Pol
int n, a, b, c, d, e;
long long fac[100010], inv[100010];
void init_C(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % p;
  inv[n] = pow_mod(fac[n], p - 2);
  for (int i = n - 1; ~i; --i) inv[i] = inv[i + 1] * (i + 1) % p;
}
long long C(int n, int m) {
  return (n < m || m < 0) ? 0 : fac[n] * inv[m] % p * inv[n - m] % p;
}
int f[100010 * 2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  init_C(n);
  for (int i = 1; i <= n; ++i) {
    char s[10];
    cin >> s;
    if (s[0] == '?' && s[1] == '?')
      ++e;
    else if (s[0] == '?' && s[1] == 'W' || s[0] == 'W' && s[1] == '?')
      ++c;
    else if (s[0] == '?' && s[1] == 'B' || s[0] == 'B' && s[1] == '?')
      ++d;
    else if (s[0] == 'W' && s[1] == 'W')
      ++a;
    else if (s[0] == 'B' && s[1] == 'B')
      ++b;
  }
  int k = n + a - b, len = 2 * n + 1;
  vector<int> A(len), B(len);
  A[k] = 1;
  for (int i = 0; i <= c; ++i) B[i] = C(c, i);
  A = Pol::operator*(A, B);
  A.resize(len);
  for (int i = 0; i < len; ++i) B[i] = 0;
  for (int i = 0; i <= d; ++i) B[i] = C(d, i);
  A = Pol::operator*(A, B);
  for (int i = 0; i + d < A.size(); ++i) A[i] = A[i + d];
  A.resize(len);
  B.resize(len + e);
  for (int i = 0; i < len + e; ++i) B[i] = 0;
  B[0] = B[1] = B[2] = 1;
  B = Pol::Pow(B, e);
  A = Pol::operator*(A, B);
  for (int i = 0; i + e < A.size(); ++i) A[i] = A[i + e];
  A.resize(len);
  cout << A[n] << "\n";
  return 0;
}
