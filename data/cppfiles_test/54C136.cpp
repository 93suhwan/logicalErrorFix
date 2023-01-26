#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B, typename C>
struct triple {
  A X;
  B Y;
  C Z;
  triple(A a = 0, B b = 0, C c = 0) : X(a), Y(b), Z(c) {}
};
template <typename A, typename B, typename C>
triple<A, B, C> make_triple(A a = 0, B b = 0, C c = 0) {
  return triple<A, B, C>(a, b, c);
}
template <typename A, typename B, typename C>
bool operator<(const triple<A, B, C>& a, const triple<A, B, C>& b) {
  if (a.X != b.X) return a.X < b.X;
  if (a.Y != b.Y) return a.Y < b.Y;
  return a.Z < b.Z;
}
template <typename T, typename SS>
ostream& operator<<(ostream& ofs, const pair<T, SS>& p) {
  ofs << "( " << p.first << " , " << p.second << " )";
  return ofs;
}
template <typename T>
void print(T a) {
  for (auto i : a) cout << i << ' ';
  cout << '\n';
}
template <typename T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
template <typename T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T, typename D>
D min(T a) {
  return *min_element(a.begin(), a.end());
}
template <typename T, typename D>
D max(T a) {
  return *max_element(a.begin(), a.end());
}
struct custom_hash {
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
};
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<vector<pair<long long, long long> > > g(n);
  for (long long _ = 0; _ < (m); _++) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    string s;
    cin >> s;
    long long t = 0;
    if (s[0] == 'i') t = 1;
    g[x].push_back(make_pair(y, t));
    g[y].push_back(make_pair(x, t));
  }
  long long sz = 0, cn = 0;
  vector<long long> usd(n, -1);
  bool ok = 1;
  function<void(long long, long long)> dfs = [&](long long v, long long clr) {
    usd[v] = clr;
    if (clr) cn++;
    sz++;
    for (auto [to, x] : g[v]) {
      if (usd[to] == -1) dfs(to, clr ^ x);
      if (usd[to] != (clr ^ x)) ok = 0;
    }
  };
  long long ans = 0;
  for (long long i = 0; i < (n); i++)
    if (usd[i] == -1) {
      sz = 0, cn = 0;
      dfs(i, 0);
      if (!ok) return void(cout << "-1\n");
      ans += max(sz - cn, cn);
    }
  cout << ans << '\n';
}
signed main() {
  if (0) {
    freopen(
        ""
        ".in",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
  srand(time(NULL));
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long t;
  t = 1;
  cin >> t;
  for (long long _ = 0; _ < (t); _++) solve();
}
