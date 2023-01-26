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
inline void show() { ; }
inline void print(int x) { cerr << x; }
inline void print(long x) { cerr << x; }
inline void print(long long x) { cerr << x; }
inline void print(unsigned x) { cerr << x; }
inline void print(unsigned long long x) { cerr << x; }
inline void print(float x) { cerr << x; }
inline void print(double x) { cerr << x; }
inline void print(long double x) { cerr << x; }
inline void print(char x) { cerr << "\'" << x << "\'"; }
inline void print(string x) { cerr << '\"' << x << '\"'; }
inline void print(bool x) { cerr << (x ? "True" : "False"); }
template <typename T, typename H>
inline void print(pair<T, H> x) {
  cerr << "(";
  print(x.first);
  cerr << ":";
  print(x.second);
  cerr << ")";
}
template <typename T>
inline void print(T vec) {
  int cnt = 0;
  cerr << "{";
  for (auto i : vec) cerr << (cnt++ ? "," : ""), print(i);
  cerr << "}";
}
template <typename Now, typename... Next>
inline void show(Now now, Next... next) {
  print(now);
  if (sizeof...(next)) cerr << ",";
  show(next...);
}
mt19937_64 rd(chrono ::steady_clock ::now().time_since_epoch().count());
void Running_time() {
  cerr << "Running Time: " << clock() / double(1000) << "s\n";
}
const double PI = acos(-1);
const int mn = 1e6 + 7;
const int mm = 1e4 + 5;
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
ii<ll> nunu[mn];
bool cmp1(i4<ll> a, i4<ll> b) {
  if (a[0] == b[0]) return a[1] < b[1];
  return a[0] < b[0];
}
int fin(int x) { return ((x == P[x]) ? x : P[x] = fin(P[x])); }
void connect(int x, int y) {
  x = fin(x);
  y = fin(y);
  if (x == y) return;
  if (rak[x] == rak[y]) rak[x]++;
  if (rak[x] > rak[y]) {
    P[y] = x;
    nunu[x].first = min(nunu[x].first, nunu[y].first);
    nunu[x].second = max(nunu[x].second, nunu[y].second);
  } else {
    P[y] = x;
    nunu[y].first = min(nunu[x].first, nunu[y].first);
    nunu[y].second = max(nunu[x].second, nunu[y].second);
  }
  return;
}
bool cmppp(ii<ll> a, ii<ll> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first > b.first;
}
void solve() {
  cin >> n >> k;
  for (ll i = 1; i <= n; ++i) P[i] = i, rak[i] = 0;
  vector<ll> vec[2];
  for (ll i = 1; i <= n; ++i) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    nunu[i] = {a[i][2], a[i][2]};
    a[i][3] = i;
    vec[0].emplace_back(a[i][0]);
    vec[1].emplace_back(a[i][1]);
  }
  sort(begin(vec[0]), end(vec[0]));
  sort(begin(vec[1]), end(vec[1]));
  vector<ii<ll> > adj[2][max(int(vec[0].size()), int(vec[1].size()))];
  for (ll i = 1; i <= n; ++i) {
    adj[0][lower_bound(begin(vec[0]), end(vec[0]), a[i][0]) - begin(vec[0])]
        .push_back({a[i][1], i});
    adj[1][lower_bound(begin(vec[1]), end(vec[1]), a[i][1]) - begin(vec[1])]
        .push_back({a[i][0], i});
  }
  for (ll i = 0; i <= int(vec[0].size()) - 1; ++i) {
    if (int(adj[0][i].size()) <= 1) continue;
    sort(begin(adj[0][i]), end(adj[0][i]));
    for (ll j = 0; j <= int(adj[0][i].size()) - 1; ++j) {
      if (j < int(adj[0][i].size()) - 1) {
        ii<ll> now = adj[0][i][j];
        ii<ll> next = adj[0][i][j + 1];
        if (next.first - now.first <= k) {
          connect(now.second, next.second);
        }
      }
    }
  }
  for (ll i = 0; i <= int(vec[1].size()) - 1; ++i) {
    if (int(adj[1][i].size()) <= 1) continue;
    sort(begin(adj[1][i]), end(adj[1][i]));
    for (ll j = 0; j <= int(adj[1][i].size()) - 1; ++j) {
      if (j < int(adj[1][i].size()) - 1) {
        ii<ll> now = adj[1][i][j];
        ii<ll> next = adj[1][i][j + 1];
        if (next.first - now.first <= k) {
          connect(now.second, next.second);
        }
      }
    }
  }
  vector<ii<ll> > UwU;
  for (ll i = 1; i <= n; ++i)
    if (P[i] == i) {
      UwU.push_back(nunu[i]);
    }
  sort(begin(UwU), end(UwU), cmppp);
  int times = -1;
  ll ans = -1;
  for (auto i : UwU) {
    if (i.first <= times) break;
    times++;
    ans++;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T-- > 0) {
    solve();
  }
  Running_time();
  return (0 - 0);
}
