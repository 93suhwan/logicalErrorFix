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
ll n, k, pre[N], suf[N];
vc<ll> a;
ll evan(int i, int j) {
  if (a[i] < 0 && a[j] > 0 || a[i] > 0 && a[j] < 0) return 2 * abs(a[i] - a[j]);
  return 2 * max(abs(a[i]), abs(a[j]));
}
ll evan2(int i, int j) {
  if (a[i] < 0 && a[j] > 0 || a[i] > 0 && a[j] < 0)
    return evan(i, j) - max(abs(a[i]), abs(a[j]));
  return max(abs(a[i]), abs(a[j]));
}
ll blah() {
  ll ans = 0;
  for (int i = 0; i + k - 1 < a.size(); i += k) ans += evan(i, i + k - 1);
  if (a.size() % k)
    return ans + evan(a.size() - (a.size() % k), a.size() - 1);
  else
    return ans;
}
void solve() {
  a.clear();
  cin >> n >> k;
  while (n--) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  if (abs(a[0]) > abs(a.back())) reverse(a.begin(), a.end());
  ll ans = evan2(a.size() - k, a.size() - 1);
  for (int i = 0; i < k; ++i) a.pop_back();
  ll x = blah();
  reverse(a.begin(), a.end());
  x = min(x, blah());
  cout << ans + x << el;
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
