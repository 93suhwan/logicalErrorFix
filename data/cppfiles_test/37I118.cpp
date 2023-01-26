#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
template <typename T>
void print(vector<T> v) {
  for (T i : v) cout << i << " ";
  cout << '\n';
}
template <typename T>
void print(vector<vector<T>>& v) {
  for (vector<T>& vv : v) {
    for (T& i : vv) cout << i << " ";
    cout << '\n';
  }
}
template <typename T>
void print(T&& t) {
  cout << t << '\n';
}
template <typename T, typename... Args>
void print(T&& t, Args&&... args) {
  cout << t << " ";
  print(forward<Args>(args)...);
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V>& x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T& x) {
  int f = 0;
  cerr << '{';
  for (auto& i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
struct Dsu {
  vector<ll> parent, rank;
  Dsu(ll n) {
    parent.resize(n + 1);
    rank.resize(n + 1, 1);
    iota(begin(parent), end(parent), 0);
  }
  void out() {
    print(rank);
    print(parent);
  }
  vector<ll> getparent() { return parent; }
  vector<ll> getrank() { return rank; }
  ll find(ll x) {
    if (parent[x] == x) {
      return x;
    }
    return parent[x] = find(parent[x]);
  }
  void Union(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x != y) {
      if (rank[x] < rank[y]) swap(x, y);
      rank[x] += rank[y];
      parent[y] = x;
    }
  }
};
void loop() {
  ll n, m;
  cin >> n >> m;
  vector<array<ll, 3>> v(m);
  for (ll i = 0; i < m; i++) {
    ll x, y, z;
    cin >> x >> y >> z;
    v[i] = {x, y, z};
  }
  Dsu dsu = Dsu(n);
  vector<array<ll, 2>> ans;
  vector<ll> vis(n + 1);
  for (ll i = 0; i < m; i++) {
    vis[v[i][0]] = 1;
    vis[v[i][2]] = 1;
    ans.push_back({v[i][0], v[i][2]});
    dsu.Union(v[i][0], v[i][2]);
  }
  vector<ll> r = dsu.getrank();
  ll to = -1;
  for (ll i = 1; i <= n; i++) {
    if (r[i] > 1) {
      to = i;
      break;
    }
  }
  for (ll i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      vis[i] = 1;
      ans.push_back({to, i});
    }
  }
  vector<ll> P;
  for (ll i = 1; i <= n; i++) {
    if (r[i] > 1) {
      P.push_back(i);
    }
  }
  for (ll i = 0; i < P.size() - 1; i++) {
    ans.push_back({P[i], P[i + 1]});
  }
  for (auto i : ans) {
    cout << i[0] << ' ' << i[1] << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin >> t;
  while (t--) {
    loop();
  }
}
