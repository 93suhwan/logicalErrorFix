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
  long long n;
  cin >> n;
  vector<vector<long long> > g(n);
  for (long long i = 0; i < (n); i++) {
    long long k;
    cin >> k;
    for (long long _ = 0; _ < (k); _++) {
      long long x;
      cin >> x;
      x--;
      g[x].push_back(i);
    }
  }
  vector<long long> usd(n);
  function<long long(long long)> dfs = [&](long long v) {
    usd[v] = 1;
    for (auto to : g[v])
      if (usd[to] == 1)
        return 1;
      else if (!usd[to] && dfs(to))
        return 1;
    usd[v] = 2;
    return 0;
  };
  for (long long i = 0; i < (n); i++)
    if (!usd[i])
      if (dfs(i)) return void(cout << "-1\n");
  vector<vector<long long> > rg(n);
  vector<long long> in(n);
  for (long long i = 0; i < (n); i++)
    for (auto x : g[i])
      if (i > x) rg[i].push_back(x), in[x]++;
  vector<long long> d(n);
  queue<long long> q;
  for (long long i = 0; i < (n); i++)
    if (!in[i]) q.push(i);
  while ((long long)(q.size())) {
    long long v = q.front();
    q.pop();
    for (auto to : rg[v]) {
      d[to] = max(d[to], d[v] + 1);
      in[to]--;
      if (!in[to]) q.push(to);
    }
  }
  cout << 1 + *max_element(d.begin(), d.end()) << '\n';
};
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
  long long t = 1;
  cin >> t;
  for (long long _ = 0; _ < (t); _++) solve();
}
