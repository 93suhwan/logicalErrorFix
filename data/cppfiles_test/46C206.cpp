#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vc = vector<T>;
template <typename T>
using uset = unordered_set<T>;
template <typename A, typename B>
using umap = unordered_map<A, B>;
template <typename T, typename Comp>
using pq = std::priority_queue<T, vc<T>, Comp>;
template <typename T>
using maxpq = pq<T, less<T>>;
template <typename T>
using minpq = pq<T, greater<T>>;
using db = double;
using ld = long double;
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vc<int>;
using vll = vc<ll>;
using vpi = vc<pi>;
using vpll = vc<pll>;
using str = string;
constexpr char el = '\n';
constexpr char sp = ' ';
constexpr int inf = 0x3f3f3f3f;
constexpr ll llinf = 0x3f3f3f3f3f3f3f3fLL;
const int N = 2e5 + 5;
int n, a[N];
void solve() {
  cin >> n;
  int mo = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    mo = max(mo, a[i]);
  }
  if (a[n - 1] == mo) {
    cout << 0 << el;
    return;
  }
  int ans = 1;
  int cur = a[n - 1];
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == mo) {
      cout << ans << el;
      return;
    }
    if (a[i] > cur) {
      ++ans;
      cur = a[i];
    }
  }
  exit(6969);
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed;
  clog << fixed;
  clog << unitbuf;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
