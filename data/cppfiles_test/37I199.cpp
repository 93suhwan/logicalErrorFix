#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &i : v) is >> i;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &p) {
  for (T x : p) os << x << " ";
  os << '\n';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &p) {
  os << "{ ";
  for (T x : p) os << x << " ";
  os << "}" << '\n';
  return os;
}
template <typename Tk, typename Tv>
ostream &operator<<(ostream &os, const map<Tk, Tv> &p) {
  os << "{ ";
  for (pair<Tk, Tv> x : p) os << x << " ";
  os << "}" << '\n';
  return os;
}
template <typename Tk, typename Tv>
ostream &operator<<(ostream &os, const pair<Tk, Tv> &p) {
  os << "{" << p.first << ',' << p.second << "}";
  return os;
}
void dfs(long long int node, long long int par, vector<set<long long int>> &vsi,
         vector<long long int> &seen) {
  for (auto x : vsi[node]) {
    if (x != par) {
      cout << node + 1 << " " << x + 1 << '\n';
      dfs(x, node, vsi, seen);
    }
    seen[node] = true;
  }
}
void solve() {
  long long int n, m, a, b, c;
  cin >> n >> m;
  vector<long long int> taken(n, 0), seen(n, 0);
  vector<set<long long int>> vsi(n);
  for (long long int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    a--, c--;
    if (!taken[a] or !taken[c]) {
      vsi[a].insert(c);
      vsi[c].insert(a);
      taken[a] = 1;
      taken[c] = 1;
    }
  }
  long long int ft = -1;
  for (long long int i = 0; i < n; i++)
    if (taken[i]) {
      ft = i;
      break;
    }
  for (long long int i = 0; i < n; i++) {
    if (!taken[i]) {
      vsi[i].insert(ft);
      vsi[ft].insert(i);
    }
  }
  dfs(0, -1, vsi, seen);
  for (long long int i = 1; i < n; i++) {
    if (!seen[i]) {
      cout << 1 << " " << i + 1 << '\n';
      dfs(i, 0, vsi, seen);
    }
  }
}
int32_t main() {
  auto start = high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int tc;
  cin >> tc;
  for (long long int t = 1; t <= tc; t++) {
    solve();
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
}
