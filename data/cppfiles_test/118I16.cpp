#include <bits/stdc++.h>
using namespace std;
const int INFi = 1e9 + 5;
const int maxN = 2e5 + 5e4 + 5;
const int md = 998244353;
const long long INF = 2e18;
double getTime() { return clock() / (double)CLOCKS_PER_SEC; }
inline int add(const int &a, const int &b) {
  return a + b >= md ? a + b - md : a + b;
}
inline int sub(const int &a, const int &b) {
  return a - b < 0 ? a - b + md : a - b;
}
inline int mul(const int &a, const int &b) { return (1ll * a * b) % md; }
int binpow(int a, int b) {
  if (b <= 0) return 1;
  if (b % 2) return mul(a, binpow(a, b - 1));
  int m = binpow(a, b / 2);
  return mul(m, m);
}
int rev(int a) { return binpow(a, md - 2); }
const int maxF = 2e5 + 5e4 + 5;
int fact[maxF];
int rfact[maxF];
void init() {
  fact[0] = 1;
  for (int i = 1; i < maxF; ++i) fact[i] = mul(fact[i - 1], i);
  rfact[maxF - 1] = rev(fact[maxF - 1]);
  for (int i = maxF - 1; i >= 1; --i) {
    rfact[i - 1] = mul(rfact[i], i);
  }
}
int C(int n, int k) {
  if (k < 0 || n < k) return 0;
  return mul(fact[n], mul(rfact[k], rfact[n - k]));
}
int psq[maxN];
void initFFT() {
  int s = 31;
  for (int i = (1 << 23); i >= 1; i /= 2, s = mul(s, s)) {
    if (i < maxN) psq[i] = s;
  }
}
void fft(vector<int> &s, vector<int> &res, int n, int x, int ss = 0,
         int step = 1, int rs = 0) {
  if (n == 1) {
    res[rs] = s[ss];
    return;
  }
  fft(s, res, n / 2, mul(x, x), ss, step * 2, rs);
  fft(s, res, n / 2, mul(x, x), ss + step, step * 2, rs + n / 2);
  int c = 1;
  for (int i = rs; i < rs + n / 2; ++i) {
    auto a = res[i], b = res[i + n / 2];
    res[i] = add(a, mul(b, c));
    res[i + n / 2] = sub(a, mul(b, c));
    c = mul(c, x);
  }
}
vector<int> multiply(vector<int> &a, vector<int> &b) {
  vector<int> as(a.begin(), (a).end()), bs(b.begin(), (b).end());
  int n = 1;
  while (n < a.size() || n < b.size()) n *= 2;
  n *= 2;
  as.resize(n);
  bs.resize(n);
  int t = psq[n];
  vector<int> resa(n), resb(n);
  fft(as, resa, n, t);
  fft(bs, resb, n, t);
  for (int i = 0; i < (n); ++i) resa[i] = mul(resa[i], resb[i]);
  t = rev(t);
  fft(resa, as, n, t);
  int rn = rev(n);
  for (int i = 0; i < (n); ++i) as[i] = mul(as[i], rn);
  return as;
}
int cnt[maxN];
vector<int> aboba(int l, int r) {
  if (l >= r) return {0, 1};
  if (l + 1 == r) {
    return {cnt[l], 1};
  }
  int m = (l + r + 1) / 2;
  vector<int> a1 = aboba(l, m), a2 = aboba(m, r);
  vector<int> a3 = multiply(a1, a2);
  while ((int)a3.size() > 1 && a3.back() == 0) {
    a3.pop_back();
  }
  return a3;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int a, b;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> par(n);
  vector<bool> used(n, false);
  vector<int> st = {0};
  used[0] = true;
  while (!st.empty()) {
    int v = st.back();
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
  vector<int> kekis = aboba(0, n);
  int ans = fact[n];
  for (int w = 1; w < n; w++) {
    int kek = fact[n - w];
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
