#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
using ll = long long;
using ull = unsigned long long;
mt19937 rng(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const int maxn = 3e5 + 10;
ll qpow(ll a, int b) {
  ll ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
const int G = 3;
namespace NTT {
ll wn[maxn << 2], rev[maxn << 2];
int init(int n_) {
  int step = 0;
  int n = 1;
  for (; n < n_; n <<= 1) ++step;
  for (int i = int(1); i <= (int)(n - 1); i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (step - 1));
  int g = qpow(G, (mod - 1) / n);
  wn[0] = 1;
  for (int i = 1; i <= n; ++i) wn[i] = wn[i - 1] * g % mod;
  return n;
}
void NTT(ll a[], int n, int f) {
  for (int i = int(0); i <= (int)(n - 1); i++)
    if (i < rev[i]) std::swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += (k << 1)) {
      int t = n / (k << 1);
      for (int j = int(0); j <= (int)(k - 1); j++) {
        ll w = f == 1 ? wn[t * j] : wn[n - t * j];
        ll x = a[i + j];
        ll y = a[i + j + k] * w % mod;
        a[i + j] = (x + y) % mod;
        a[i + j + k] = (x - y + mod) % mod;
      }
    }
  }
  if (f == -1) {
    ll ninv = qpow(n, mod - 2);
    for (int i = int(0); i <= (int)(n - 1); i++) a[i] = a[i] * ninv % mod;
  }
}
ll tmp1[maxn << 2], tmp2[maxn << 2];
void mul(ll a[], ll b[], int lena, int lenb) {
  int len = init(lena + lenb + 2);
  for (int i = int(0); i <= (int)(lena - 1); i++) tmp1[i] = a[i];
  for (int i = int(lena); i <= (int)(len - 1); i++) tmp1[i] = 0;
  for (int i = int(0); i <= (int)(lenb - 1); i++) tmp2[i] = b[i];
  for (int i = int(lenb); i <= (int)(len - 1); i++) tmp2[i] = 0;
  NTT(tmp1, len, 1);
  NTT(tmp2, len, 1);
  for (int i = int(0); i <= (int)(len - 1); i++) a[i] = tmp1[i] * tmp2[i] % mod;
  NTT(a, len, -1);
}
void mul(ll a[], ll b[], ll c[], int lena, int lenb) {
  int len = init(lena + lenb + 2);
  for (int i = int(0); i <= (int)(lena - 1); i++) tmp1[i] = a[i];
  for (int i = int(lena); i <= (int)(len - 1); i++) tmp1[i] = 0;
  for (int i = int(0); i <= (int)(lenb - 1); i++) tmp2[i] = b[i];
  for (int i = int(lenb); i <= (int)(len - 1); i++) tmp2[i] = 0;
  NTT(tmp1, len, 1);
  NTT(tmp2, len, 1);
  for (int i = int(0); i <= (int)(len - 1); i++) c[i] = tmp1[i] * tmp2[i] % mod;
  NTT(c, len, -1);
}
ll P[20][maxn << 2];
void solve(ll *a, int l, int r, int dep) {
  if (l == r) {
    P[dep][2 * l] = 1;
    P[dep][2 * l + 1] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  solve(a, l, mid, dep + 1);
  solve(a, mid + 1, r, dep + 1);
  int lenl = mid - l + 1, lenr = r - mid;
  mul(P[dep + 1] + 2 * l, P[dep + 1] + 2 * mid + 2, P[dep] + l * 2, lenl + 1,
      lenr + 1);
}
}  // namespace NTT
ll du[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = int(1); i <= (int)(n - 1); i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    du[u]++;
    du[v]++;
  }
  for (int i = int(1); i <= (int)(n - 1); i++) {
    du[i]--;
  }
  NTT::solve(du, 0, n - 1, 0);
  vector<ll> jc(n + 1);
  jc[0] = 1;
  for (int i = int(1); i <= (int)(n); i++) {
    jc[i] = jc[i - 1] * i % mod;
  }
  ll ans = 0;
  for (int i = int(0); i <= (int)(n); i++) {
    ll val = NTT::P[0][i] * jc[n - i] % mod;
    if (i & 1)
      ans = (ans + mod - val) % mod;
    else
      ans = (ans + val) % mod;
  }
  cout << ans << '\n';
  return 0;
}
