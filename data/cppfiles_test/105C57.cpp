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
const int N = 2e6 + 1;
vector<array<int, 4>> c[N];
void solve() {
  int n;
  cin >> n;
  vi used;
  vector<array<int, 3>> vals(n);
  for (int i = (0); i < (n); ++i) {
    int x, y, m;
    cin >> x >> y >> m;
    used.push_back(x + y - m);
    c[x + y - m].push_back({x, y, m, i});
    vals[i] = {x, y, m};
  }
  42;
  sort((used).begin(), (used).end()),
      used.resize(unique((used).begin(), (used).end()) - begin(used));
  vpi ans(n);
  int res = 0;
  for (auto x : used) {
    vector<array<int, 3>> intervals;
    for (auto [a, b, m, id] : c[x]) {
      int L = max(0, m - b);
      int R = min(a, m);
      intervals.push_back({a - R, a - L, id});
    }
    sort((intervals).begin(), (intervals).end(),
         [&](array<int, 3> &lhs, array<int, 3> &rhs) {
           return lhs[1] < rhs[1];
         });
    42;
    for (int i = (0); i < ((int)(intervals).size()); ++i) {
      auto [L, R, id] = intervals[i];
      res++;
      ans[id] = {vals[id][0] - R, (vals[id][2] - (vals[id][0] - R))};
      42;
      while (i + 1 < (int)(intervals).size() && intervals[i + 1][0] <= R) {
        i++;
        id = intervals[i][2];
        ans[id] = {vals[id][0] - R, (vals[id][2] - (vals[id][0] - R))};
      }
    }
    c[x].clear();
  }
  cout << res << "\n";
  for (auto [x, y] : ans) cout << x << " " << y << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int testcase = 1;
  cin >> testcase;
  while (testcase--) {
    solve();
  }
}
