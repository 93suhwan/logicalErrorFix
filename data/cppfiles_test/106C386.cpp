#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
template <class T>
using V = vector<T>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;
template <class T>
int lwb(V<T>& a, const T& b) {
  return int(lower_bound(begin(a), end(a), b) - begin(a));
}
template <class T>
int upb(V<T>& a, const T& b) {
  return int(upper_bound(begin(a), end(a), b) - begin(a));
}
const ll M = 1e9 + 7;
const ll MX = 1e9;
const ll INF = 1e18;
const db PI = acos((db)-1);
const int ddef[4]{1, 0, -1, 0}, dataq[4]{0, 1, 0, -1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); }
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); }
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); }
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
void setIO(string name = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if (int((name).size())) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}
int test;
void solve() {
  int n;
  cin >> n;
  for (int i = (0); i < (n); ++i) cout << i + 2 << " ";
  cout << "\n";
}
int main() {
  int TC = 1;
  cin >> TC;
  for (test = 1; test <= TC; test++) solve();
  return 0;
}
