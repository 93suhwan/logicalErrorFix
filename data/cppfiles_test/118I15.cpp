#include <bits/stdc++.h>
using namespace std;
const long long INFi = 1e9 + 5;
const long long maxN = 2e5 + 5e4 + 5;
const long long md = 998244353;
const long long INF = 2e18;
double getTime() { return clock() / (double)CLOCKS_PER_SEC; }
inline long long add(const long long &a, const long long &b) {
  return a + b >= md ? a + b - md : a + b;
}
inline long long sub(const long long &a, const long long &b) {
  return a - b < 0 ? a - b + md : a - b;
}
inline long long mul(const long long &a, const long long &b) {
  return (1ll * a * b) % md;
}
long long binpow(long long a, long long b) {
  if (b <= 0) return 1;
  if (b % 2) return mul(a, binpow(a, b - 1));
  long long m = binpow(a, b / 2);
  return mul(m, m);
}
long long rev(long long a) { return binpow(a, md - 2); }
const long long maxF = 2e5 + 5e4 + 5;
long long fact[maxF];
long long rfact[maxF];
void init() {
  fact[0] = 1;
  for (long long i = 1; i < maxF; ++i) fact[i] = mul(fact[i - 1], i);
  rfact[maxF - 1] = rev(fact[maxF - 1]);
  for (long long i = maxF - 1; i >= 1; --i) {
    rfact[i - 1] = mul(rfact[i], i);
  }
}
long long C(long long n, long long k) {
  if (k < 0 || n < k) return 0;
  return mul(fact[n], mul(rfact[k], rfact[n - k]));
}
long long psq[maxN];
void initFFT() {
  long long s = 31;
  for (long long i = (1 << 23); i >= 1; i /= 2, s = mul(s, s)) {
    if (i < maxN) psq[i] = s;
  }
}
void fft(vector<long long> &s, vector<long long> &res, long long n, long long x,
         long long ss = 0, long long step = 1, long long rs = 0) {
  if (n == 1) {
    res[rs] = s[ss];
    return;
  }
  fft(s, res, n / 2, mul(x, x), ss, step * 2, rs);
  fft(s, res, n / 2, mul(x, x), ss + step, step * 2, rs + n / 2);
  long long c = 1;
  for (long long i = rs; i < rs + n / 2; ++i) {
    auto a = res[i], b = res[i + n / 2];
    res[i] = add(a, mul(b, c));
    res[i + n / 2] = sub(a, mul(b, c));
    c = mul(c, x);
  }
}
vector<long long> multiply(vector<long long> &a, vector<long long> &b) {
  vector<long long> as(a.begin(), (a).end()), bs(b.begin(), (b).end());
  long long n = 1;
  while (n < a.size() || n < b.size()) n *= 2;
  n *= 2;
  as.resize(n);
  bs.resize(n);
  long long t = psq[n];
  vector<long long> resa(n), resb(n);
  fft(as, resa, n, t);
  fft(bs, resb, n, t);
  for (long long i = 0; i < (n); ++i) resa[i] = mul(resa[i], resb[i]);
  t = rev(t);
  fft(resa, as, n, t);
  long long rn = rev(n);
  for (long long i = 0; i < (n); ++i) as[i] = mul(as[i], rn);
  return as;
}
long long cnt[maxN];
vector<long long> aboba(long long l, long long r) {
  if (l >= r) return {0, 1};
  if (l + 1 == r) {
    return {cnt[l], 1};
  }
  long long m = (l + r + 1) / 2;
  vector<long long> a1 = aboba(l, m), a2 = aboba(m, r);
  vector<long long> a3 = multiply(a1, a2);
  while ((long long)a3.size() > 1 && a3.back() == 0) {
    a3.pop_back();
  }
  return a3;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n;
  cin >> n;
  long long a, b;
  vector<vector<long long>> g(n);
  for (long long i = 0; i < n - 1; i++) {
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<long long> par(n);
  vector<bool> used(n, false);
  vector<long long> st = {0};
  used[0] = true;
  while (!st.empty()) {
    long long v = st.back();
    st.pop_back();
    for (auto u : g[v]) {
      if (!used[u]) {
        cnt[v]++;
        used[u] = true;
        st.push_back(u);
      }
    }
  }
  init();
  initFFT();
  vector<long long> kekis = aboba(0, n);
  long long ans = fact[n];
  for (long long w = 1; w < n; w++) {
    long long kek = fact[n - w];
    kek = mul(kek, kekis[n - w]);
    if (w % 2 == 0) {
      ans = add(ans, kek);
    } else {
      ans = add(ans, md - kek);
    }
  }
  ans %= md;
  cout << ans << '\n';
}
