#include <bits/stdc++.h>
#pragma GCC optimize "trapv"
using namespace std;
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) {
  return (istream >> p.first >> p.second);
}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v) {
  for (auto &it : v) cin >> it;
  return istream;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) {
  return (ostream << p.first << " " << p.second);
}
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
  for (auto &it : c) cout << it << " ";
  return ostream;
}
vector<pair<int, int> > dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
struct DSU {
  vector<int> par;
  vector<int> sze;
  int connected;
  void ini(int n) {
    par.resize(n + 1);
    sze.assign(n + 1, 1);
    iota((par).begin(), (par).end(), 0);
    connected = n;
  }
  int get(int x) { return (par[x] = (par[x] == x ? x : get(par[x]))); }
  int getSize(int u) { return sze[get(u)]; }
  void un(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) {
      return;
    }
    sze[y] += sze[x];
    sze[x] = 0;
    par[x] = y;
    connected--;
  }
};
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  cin >> v;
  vector<int> vc = v;
  sort((vc).begin(), (vc).end());
  map<int, int> m;
  for (int i = 0; 0 < n ? i < n : i > n; 0 < n ? i += 1 : i -= 1) m[v[i]]++;
  if (m.size() < n) {
    cout << "YES\n";
    return;
  }
  DSU dsu;
  dsu.ini(n + 1);
  for (int i = 0; 0 < n ? i < n : i > n; 0 < n ? i += 1 : i -= 1)
    dsu.un(v[i], i + 1);
  int s = 0;
  map<int, int> f;
  for (int i = 1; 1 < n + 1 ? i < n + 1 : i > n + 1;
       1 < n + 1 ? i += 1 : i -= 1) {
    if (f[dsu.get(i)] == 0 && dsu.getSize(i) % 2 == 0) {
      s++;
      f[dsu.get(i)] = 1;
    }
  }
  if (s % 2)
    cout << "NO";
  else
    cout << "YES";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cout << fixed << setprecision(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  };
  return 0;
}
