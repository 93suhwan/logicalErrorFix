#include <bits/stdc++.h>
using namespace std;
using ll = long long;
inline void read() { ; }
template <typename T, typename... H>
inline void read(T x, H... y) {
  x = 0;
  char c = getchar();
  bool am = false;
  while (!isdigit(c)) am |= (c == '-'), c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  if (am) x = -x;
  read(y...);
}
const double PI = acos(-1);
const long long mn = 1e6 + 7;
const long long mm = 1e4 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
template <typename T>
using ii = pair<T, T>;
template <typename T>
using i3 = array<T, 3>;
template <typename T>
using i4 = array<T, 4>;
i4<ll> a[mn];
ll n, k, P[mn], rak[mn];
long long fin(long long x) { return ((x == P[x]) ? x : P[x] = fin(P[x])); }
void connect(long long x, long long y) {
  x = fin(x);
  y = fin(y);
  if (x == y) return;
  if (rak[x] == rak[y]) rak[x]++;
  if (rak[x] > rak[y]) {
    P[y] = x;
    a[x][2] = min(a[x][2], a[y][2]);
  } else {
    P[y] = x;
    a[y][2] = min(a[y][2], a[x][2]);
  }
  return;
}
void solve() {
  cin >> n >> k;
  for (ll i = 1; i <= n; ++i) P[i] = i, rak[i] = 0;
  vector<ll> vec[2];
  for (ll i = 1; i <= n; ++i) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    vec[0].emplace_back(a[i][0]);
    vec[1].emplace_back(a[i][1]);
  }
  sort(begin(vec[0]), end(vec[0]));
  sort(begin(vec[1]), end(vec[1]));
  vec[0].resize(unique(begin(vec[0]), end(vec[0])) - begin(vec[0]));
  vec[1].resize(unique(begin(vec[1]), end(vec[1])) - begin(vec[1]));
  vector<ii<ll> > adj[2][max(long(vec[0].size()), long(vec[1].size())) + 10];
  for (ll i = 1; i <= n; ++i) {
    adj[0][lower_bound(begin(vec[0]), end(vec[0]), a[i][0]) - begin(vec[0])]
        .push_back({a[i][1], i});
    adj[1][lower_bound(begin(vec[1]), end(vec[1]), a[i][1]) - begin(vec[1])]
        .push_back({a[i][0], i});
  }
  for (ll i = 0; i <= long(vec[0].size()) - 1; ++i) {
    sort(begin(adj[0][i]), end(adj[0][i]));
    for (ll j = 0; j <= long(adj[0][i].size()) - 1; ++j) {
      if (j < long(adj[0][i].size()) - 1) {
        ii<ll> now = adj[0][i][j];
        ii<ll> next = adj[0][i][j + 1];
        if (next.first - now.first <= k) {
          connect(now.second, next.second);
        }
      }
    }
  }
  for (ll i = 0; i <= long(vec[1].size()) - 1; ++i) {
    sort(begin(adj[1][i]), end(adj[1][i]));
    for (ll j = 0; j <= long(adj[1][i].size()) - 1; ++j) {
      if (j < long(adj[1][i].size()) - 1) {
        ii<ll> now = adj[1][i][j];
        ii<ll> next = adj[1][i][j + 1];
        if (next.first - now.first <= k) {
          connect(now.second, next.second);
        }
      }
    }
  }
  vector<ll> UwU;
  for (ll i = 1; i <= n; ++i)
    if (P[i] == i) {
      UwU.push_back(a[i][2]);
    }
  ll ans = n;
  long long l = 0, r = n;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    long long cnt = 0;
    for (auto i : UwU) {
      if (i > mid) ++cnt;
    }
    if (cnt <= mid + 1) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long T;
  cin >> T;
  while (T-- > 0) {
    solve();
  }
  return (0 - 0);
}
