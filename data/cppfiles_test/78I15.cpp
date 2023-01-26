#define MOD_TYPE 1

#include <bits/stdc++.h>
using namespace std;

#if 1
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#if 0
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template <typename T>
using extset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#endif

#if 0
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
using Int = boost::multiprecision::cpp_int;
using lld = boost::multiprecision::cpp_dec_float_100;
#endif

#pragma region Macros

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
template <typename T>
using smaller_queue = priority_queue<T, vector<T>, greater<T>>;

constexpr ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
constexpr int INF = (int)1e9 + 10;
constexpr ll LINF = (ll)4e18;
constexpr ld PI = acos(-1.0);
constexpr ld EPS = 1e-7;
constexpr int Dx[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
constexpr int Dy[] = {1, -1, 0, 0, -1, -1, 1, 1, 0};

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define REPI(i, m, n) for (int i = m; i < (int)(n); ++i)
#define repi(i, n) REPI(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"
#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"
#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << "\n";
#define UNIQUE(v) v.erase(unique(all(v)), v.end())

struct io_init {
  io_init() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(30) << setiosflags(ios::fixed);
  };
} io_init;
template <typename T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
inline ll CEIL(ll a, ll b) { return (a + b - 1) / b; }
template <typename A, size_t N, typename T>
inline void Fill(A (&array)[N], const T &val) {
  fill((T *)array, (T *)(array + N), val);
}
template <typename T>
vector<T> compress(vector<T> &v) {
  vector<T> val = v;
  sort(all(val)), val.erase(unique(all(val)), val.end());
  for (auto &&vi : v) vi = lower_bound(all(val), vi) - val.begin();
  return val;
}
template <typename T, typename U>
constexpr istream &operator>>(istream &is, pair<T, U> &p) noexcept {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
constexpr ostream &operator<<(ostream &os, pair<T, U> &p) noexcept {
  os << p.first << " " << p.second;
  return os;
}
random_device seed_gen;
mt19937_64 engine(seed_gen());

#pragma endregion

// --------------------------------------

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll g = 0;
  rep(bit, 30) {
    ll cnt = 0;
    rep(i, n) {
      if (a[i] & (1 << i)) cnt++;
    }
    g = gcd(g, cnt);
  }
  vector<int> ans;
  if (g == 0) {
    REP(i, 1, n + 1) ans.push_back(i);
  } else {
    REP(i, 1, g + 1) {
      if (g % i == 0) ans.push_back(i);
    }
  }
  rep(i, ans.size()) cout << ans[i] << (i + 1 == ans.size() ? "\n" : " ");
}

int main() {
  int testcase;
  cin >> testcase;
  while (testcase--) solve();
}