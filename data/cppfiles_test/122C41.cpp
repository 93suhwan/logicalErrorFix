#include <bits/stdc++.h>
using namespace std;
template <typename T>
void pr(vector<T> &v) {
  for (int i = 0; i < (int)(v).size(); i++) cout << v[i] << " ";
  cout << '\n';
  ;
}
template <typename T>
void pr(vector<vector<T>> &v) {
  for (int i = 0; i < (int)(v).size(); i++) {
    pr(v[i]);
  }
}
template <typename T>
void re(T &x) {
  cin >> x;
}
template <typename T>
void re(vector<T> &a) {
  for (int i = 0; i < (int)(a).size(); i++) re(a[i]);
}
template <class Arg, class... Args>
void re(Arg &first, Args &...rest) {
  re(first);
  re(rest...);
}
template <typename T>
void pr(T x) {
  cout << x << '\n';
  ;
}
template <class Arg, class... Args>
void pr(const Arg &first, const Args &...rest) {
  cout << first << " ";
  pr(rest...);
  cout << '\n';
  ;
}
void ps() {
  cout << '\n';
  ;
}
template <class T, class... Ts>
void ps(const T &t, const Ts &...ts) {
  cout << t;
  if (sizeof...(ts)) cout << " ";
  ps(ts...);
}
const long long MOD = 998244353;
long double PI = 4 * atan(1);
long double eps = 1e-12;
int n, m;
vector<vector<pair<int, int>>> adj;
vector<pair<pair<int, int>, int>> inp;
vector<int> par;
int flg;
void dfs(int i) {
  for (pair<int, int> nxt : adj[i]) {
    if (par[nxt.first] == -1) {
      par[nxt.first] = par[i] ^ nxt.second;
      dfs(nxt.first);
    }
    if ((par[i] ^ nxt.second) != par[nxt.first]) {
      flg = 0;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int tcase = 0; tcase < t; tcase++) {
    cin >> n >> m;
    adj.clear();
    adj.resize(n);
    inp.clear();
    inp.resize(n - 1);
    par.clear();
    par.resize(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v, p;
      cin >> u >> v >> p;
      u--;
      v--;
      inp[i] = {{u, v}, p};
      if (p != -1) {
        bitset<32> b(p);
        int numbits = b.count();
        adj[u].push_back({v, numbits & 1});
        adj[v].push_back({u, numbits & 1});
      }
    }
    for (int i = 0; i < m; i++) {
      int u, v, p;
      cin >> u >> v >> p;
      u--;
      v--;
      adj[u].push_back({v, p});
      adj[v].push_back({u, p});
    }
    flg = 1;
    for (int i = 0; i < n; i++) par[i] = -1;
    for (int i = 0; i < n; i++) {
      if (par[i] == -1) {
        par[i] = 0;
        dfs(i);
      }
    }
    if (flg) {
      cout << "YES" << '\n';
      ;
      for (int i = 0; i < n - 1; i++) {
        if (inp[i].second != -1) {
          cout << inp[i].first.first + 1 << " " << inp[i].first.second + 1
               << " " << inp[i].second << '\n';
          ;
        } else {
          int ans = par[inp[i].first.first] ^ par[inp[i].first.second];
          cout << inp[i].first.first + 1 << " " << inp[i].first.second + 1
               << " " << ans << '\n';
          ;
        }
      }
    } else {
      cout << "NO" << '\n';
      ;
    }
  }
}
