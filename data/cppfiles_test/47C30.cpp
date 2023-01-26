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
ll n, k;
ll evan(const vi &v) {
  ll ans = 0;
  for (int i = v.size() - 1; i - k + 1 >= 0; i -= k) ans += 2 * v[i];
  if (v.size() % k) ans += 2 * v[v.size() % k - 1];
  return ans;
}
void solve() {
  cin >> n >> k;
  vi a, b;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (x < 0)
      a.push_back(-x);
    else if (x > 0)
      b.push_back(x);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (a.empty() && b.empty())
    cout << 0 << el;
  else if (b.empty())
    cout << evan(a) - a.back() << el;
  else if (a.empty())
    cout << evan(b) - b.back() << el;
  else
    cout << evan(a) + evan(b) - max(a.back(), b.back()) << el;
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
