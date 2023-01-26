#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vint = vector<int>;
using vpii = vector<pii>;
pii operator+(pii a, pii b) { return {a.first + b.first, a.second + b.second}; }
pll operator+(pll a, pll b) { return {a.first + b.first, a.second + b.second}; }
namespace IO {
char buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 24], *O = obuf;
inline ll read() {
  ll x = 0;
  bool sign = 0;
  char s =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 22, stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (!isdigit(s))
    sign |= s == '-',
        s = (p1 == p2 &&
                     (p2 = (p1 = buf) + fread(buf, 1, 1 << 22, stdin), p1 == p2)
                 ? EOF
                 : *p1++);
  while (isdigit(s))
    x = (x << 1) + (x << 3) + (s - '0'),
    s = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 22, stdin), p1 == p2)
             ? EOF
             : *p1++);
  return sign ? -x : x;
}
inline void print(ll x) {
  if (x < 0)
    (*O++ = '-'), print(-x);
  else {
    if (x > 9) print(x / 10);
    (*O++ = x % 10 + '0');
  }
}
}  // namespace IO
const int mod = 998244353;
const long double Pi = acos(-1);
namespace math {
const int MAXN = 2e6 + 5;
ll ksm(ll a, ll b, ll p) {
  ll s = 1, m = a;
  while (b) {
    if (b & 1) s = s * m % p;
    m = m * m % p, b >>= 1;
  }
  return s;
}
ll ksm(ll a, ll b) {
  ll s = 1, m = a;
  while (b) {
    if (b & 1) s = s * m % mod;
    m = m * m % mod, b >>= 1;
  }
  return s;
}
ll inv(ll x) { return ksm(x, mod - 2); }
ll fc[MAXN], ifc[MAXN];
void init(int n) {
  assert(n < MAXN);
  fc[0] = 1;
  for (int i = 1; i <= n; i++) fc[i] = fc[i - 1] * i % mod;
  ifc[n] = inv(fc[n]);
  for (int i = n - 1; i >= 0; i--) ifc[i] = ifc[i + 1] * (i + 1) % mod;
}
ll bin(ll n, ll m) { return fc[n] * ifc[m] % mod * ifc[n - m] % mod; }
}  // namespace math
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
using namespace IO;
const int N = 1e4 + 5;
int n, k, lim, c[N], buc[N], pre[N];
bool ok(int l, int r) {
  for (int i = l; i <= r; i++)
    if (buc[i] == lim) return 0;
  return 1;
}
void add(int l, int r) {
  for (int i = l; i <= r; i++) buc[i]++;
}
vector<pii> seq;
pii ans[N];
int main() {
  cin >> n >> k, lim = (n - 1) / (k - 1) + 1;
  for (int i = 1; i <= n * k; i++) {
    cin >> c[i];
    if (pre[c[i]]) seq.emplace_back((pii){pre[c[i]], i});
    pre[c[i]] = i;
  }
  sort(seq.begin(), seq.end());
  for (int i = seq.size() - 1; ~i; i--)
    if (ok(seq[i].first, seq[i].second))
      add(seq[i].first, seq[i].second), ans[c[seq[i].first]] = seq[i];
  for (int i = 1; i <= n; i++)
    cout << ans[i].first << " " << ans[i].second << endl;
  return 0;
}
