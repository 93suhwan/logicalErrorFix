#include <bits/stdc++.h>
using namespace std;
long long IOS = []() {
  ios::sync_with_stdio(0);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();
template <class T>
void _W(const T &x) {
  cout << x;
}
template <class T>
void _W(T &x) {
  cout << x;
}
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++)) cout << ' ';
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  cout << ", ";
  W(tail...);
}
using pii = pair<long long, long long>;
const long long N = 2e6 + 10, mod = 998244353;
inline long long quick(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
namespace Bit {
constexpr long long MAXN = 1e6 + 5;
long long n;
long long t1[MAXN], t2[MAXN];
void _add(long long l, long long c1) {
  long long c2 = c1 * l;
  for (long long i = l; i <= n; i += i & -i) t1[i] += c1, t2[i] += c2;
}
long long _qu1(long long i) {
  long long res = 0;
  for (; i > 0; i -= i & -i) res += t1[i];
  return res;
}
long long _qu2(long long i) {
  long long res = 0;
  for (; i > 0; i -= i & -i) res += t2[i];
  return res;
}
void init(long long _n) {
  n = _n;
  fill(t1, t1 + n + 1, 0);
  fill(t2, t2 + n + 1, 0);
}
void add(long long l, long long r, long long c) { _add(l, c), _add(r + 1, -c); }
long long sum(long long l, long long r) {
  return (r + 1LL) * _qu1(r) - l * _qu1(l) - (_qu2(r) - _qu2(l));
}
long long query(long long x) { return _qu1(x); }
}  // namespace Bit
void solve() {
  long long n;
  cin >> n;
  Bit::init(n + 10);
  set<long long> s;
  long long cnt = 0;
  for (long long i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    s.insert(x);
    cnt += Bit::sum(x + 1, n);
    Bit::add(x, x, 1);
  }
  if (s.size() != n || cnt % 2 == 0)
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
}
signed main() {
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
}
