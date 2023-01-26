#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using pl = pair<ll, int>;
using pll = pair<ll, ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
const int MAX_N = 1e6 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const ll N = 100001;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
clock_t startTime;
double getCurrentTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  ~debug() { cerr << endl; }
  template <class c>
  typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {
    cerr << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b>
  debug& operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c>
  debug& operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it;
    return *this << "]";
  }
};
void fastIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(20);
}
void solve() {
  int nums[3];
  for (int i = 0; i < 3; i++) cin >> nums[i];
  sort(nums, nums + 3);
  int m;
  cin >> m;
  int mn = nums[2] - nums[1] - 1;
  int mx = accumulate(nums, nums + 3, 0) - 3;
  cout << (mn <= m and m <= mx ? "YES" : "NO");
}
int main() {
  startTime = clock();
  fastIO();
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  debug() << "\nRunning Time: " << getCurrentTime() << char('s');
}
