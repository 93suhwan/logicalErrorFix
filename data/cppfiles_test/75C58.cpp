#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vpi = vector<pii>;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vpl = vector<pll>;
using ld = long double;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;
const ld PI = acos((ld)-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
bool ckmax(T &a, const T &b) {
  return b > a ? a = b, 1 : 0;
}
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
struct chash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
  size_t operator()(pair<uint64_t, uint64_t> x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x.first + FIXED_RANDOM) ^
           (splitmix64(x.second + FIXED_RANDOM) >> 1);
  }
};
void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
void solve() {
  int n;
  cin >> n;
  vi a(n), L(n), R(n);
  for (int i = (0); i < (n); ++i) {
    cin >> a[i];
  }
  for (int i = (0); i < (n); ++i) {
    if (!i || a[i - 1] <= a[i])
      L[i] = 0;
    else
      L[i] = L[i - 1] + 1;
  }
  for (int i = (n)-1; i >= (0); --i) {
    if (i == n - 1 || a[i + 1] <= a[i])
      R[i] = 0;
    else
      R[i] = R[i + 1] + 1;
  }
  42;
  function<bool(int, int, int)> rec = [&](int l, int r, int last) {
    if (l > r) return 0;
    if (a[l] <= last && a[r] <= last) return 0;
    if (a[l] <= a[r]) {
      int k = min(r - l + 1, L[r] + 1);
      if (a[r] > last && (k & 1))
        return 1;
      else if (a[l] > last)
        return (rec(l + 1, r, a[l]) ^ 1);
      else
        return 0;
    } else {
      int k = min(r - l + 1, R[l] + 1);
      if (a[l] > last && (k & 1))
        return 1;
      else if (a[r] > last)
        return (rec(l, r - 1, a[r]) ^ 1);
      else
        return 0;
    }
  };
  cout << (rec(0, n - 1, -1) ? "Alice" : "Bob") << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int testcase = 1;
  while (testcase--) {
    solve();
  }
}
