#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void read(vector<int> &a) {
  for (auto &x : a) cin >> x;
}
void read(vector<int64_t> &a) {
  for (auto &x : a) cin >> x;
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug &operator<<(const c &) {
    return *this;
  }
};
const int MOD = 1e9 + 7;
const int INF = (int)2e9 + 7;
const int64_t LINF = (int64_t)1e18;
const long double PI = 3.1415926535897932384626433832795;
void solve() {
  int n;
  cin >> n;
  vector<int64_t> v(n);
  read(v);
  sort(v.begin(), v.end());
  debug() << v;
  int64_t s = 0;
  for (int i = 0; i < n; i++) {
    s += v[i];
  }
  int idx = 0;
  for (int i = 0; i < n; i++) {
    if (s - v[i] != 0) {
      idx = i;
      break;
    }
  }
  int64_t tot = 0;
  for (int i = 0; i < n; i++) {
    if (i == idx) {
      tot += (v[i]) * (-(s - v[i]));
      cout << -(s - v[i]) << ' ';
    } else {
      tot += (v[idx]) * (v[i]);
      cout << v[idx] << ' ';
    }
  }
  debug() << tot;
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test_cases = 1;
  cin >> test_cases;
  auto t1 = high_resolution_clock::now();
  for (int tt = 1; tt <= test_cases; tt++) {
    solve();
  }
  auto t2 = high_resolution_clock::now();
  auto time = duration_cast<duration<double>>(t2 - t1);
  cerr << "Time elapsed = " << time.count() << "\n";
}
