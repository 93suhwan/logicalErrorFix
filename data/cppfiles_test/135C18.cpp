#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<long long>;
using vvi = vector<vi>;
using pii = pair<long long, long long>;
using vpii = vector<pii>;
void print() { cout << '\n'; }
template <typename x, typename... y>
void print(x a, y... b) {
  cout << a << ' ';
  print(b...);
}
ll dx[9] = {1, 0, -1, 0, -1, -1, 1, 1}, dy[9] = {0, 1, 0, -1, 1, -1, -1, 1},
   mod = 1e9 + 7, inf = 4557430888798830399LL;
template <typename T>
long long mxm(T& a, T b) {
  if (b > a) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
long long mnm(T& a, T b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
ll fpow(ll x, ll p, ll m = mod) {
  ll res = 1;
  for (; p; p >>= 1) {
    if (p & 1) res = res * x % m;
    x = x * x % m;
  }
  return res % m;
}
long long discrete(long long* a, long long l, long long r) {
  vi b(a + l, a + r + 1);
  sort((b).begin(), (b).end());
  b.erase(unique((b).begin(), (b).end()), b.end());
  for (long long i = l; i <= r; ++i)
    a[i] = 1 + lower_bound((b).begin(), (b).end(), a[i]) - b.begin();
  return b.size();
}
vi divs(long long n) {
  vi a;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      a.push_back(i);
      if (n / i != i) a.push_back(n / i);
    }
  }
  sort((a).begin(), (a).end());
  return a;
}
void add(long long* c, long long x, long long v, long long n = 1e5) {
  for (; x <= n; x += -x & x) c[x] += v;
}
long long ask(long long* c, long long x, long long ans = 0) {
  for (; x; x -= -x & x) ans += c[x];
  return ans;
}
void update(long long* c, long long x, long long v, long long n = 1e5) {
  for (; x <= n; x += -x & x) mxm(c[x], v);
}
long long query(long long* c, long long x, long long ans = 0) {
  for (; x; x -= -x & x) mxm(ans, c[x]);
  return ans;
}
long long a[200], sum[200];
long long dp[105][105];
void solve() {
  long long n, k;
  cin >> n >> k;
  for (long long i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + 1 + n);
  long long ans = 0;
  for (long long i = 1; i <= n - 2 * k; ++i) ans += a[i];
  for (long long i = n - 2 * k + 1; i <= n - k; ++i) {
    ans += a[i] / a[i + k];
  }
  print(ans);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
