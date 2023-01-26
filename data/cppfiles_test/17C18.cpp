#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-12;
const double PI = acos(-1.0);
const long long mod = 998244353;
const int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1},
          dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
void debug() { cerr << '\n'; }
template <typename T, typename... Args>
void debug(T x, Args... args) {
  cerr << "[ " << x << " ] , ";
  debug(args...);
}
mt19937 mt19937random(
    std::chrono::system_clock::now().time_since_epoch().count());
long long getRandom(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(mt19937random);
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long qmul(long long a, long long b) {
  long long r = 0;
  while (b) {
    if (b & 1) r = (r + a) % mod;
    b >>= 1;
    a = (a + a) % mod;
  }
  return r;
}
long long qpow(long long a, long long n) {
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * a) % mod;
    n >>= 1;
    a = (a * a) % mod;
  }
  return r;
}
long long qpow(long long a, long long n, long long p) {
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * a) % p;
    n >>= 1;
    a = (a * a) % p;
  }
  return r;
}
const int maxn = 200050;
struct BIT {
  int a[maxn];
  void update(int p, int v) {
    for (; p < maxn; p += p & -p) a[p] += v;
  }
  int query(int p) {
    int r = 0;
    for (; p; p -= p & -p) r += a[p];
    return r;
  }
  int query(int l, int r) { return query(r) - query(l - 1); }
} tree;
int a[200050], b[200050];
void solve() {
  int n;
  cin >> n;
  for (int i = (1); i <= (n); i++) cin >> a[i], b[i] = a[i];
  sort(b + 1, b + n + 1);
  int m = unique(b + 1, b + n + 1) - (b + 1);
  for (int i = (1); i <= (n); i++)
    a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
  for (int i = (1); i <= (m); i++) tree.a[i] = 0;
  long long r = 0;
  for (int i = (1); i <= (n); i++) {
    r += min(tree.query(a[i] - 1), tree.query(m) - tree.query(a[i]));
    tree.update(a[i], 1);
  }
  cout << r << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    solve();
  }
  return 0;
}
