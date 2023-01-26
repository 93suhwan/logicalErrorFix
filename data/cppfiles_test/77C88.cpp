#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T v) {
  cout << ((int)(v).size()) << '\n';
  for (auto x : v) cout << x << ' ';
  cout << '\n';
};
template <class T>
void print1(T v) {
  cout << ((int)(v).size()) << '\n';
  for (auto x : v) cout << x + 1 << ' ';
  cout << '\n';
};
template <class T1, class T2>
ostream& operator<<(ostream& o, pair<T1, T2> x) {
  return o << x.first << ' ' << x.second;
}
template <class T1, class T2>
istream& operator>>(istream& o, pair<T1, T2>& x) {
  return o >> x.first >> x.second;
}
template <class T1, class T2>
pair<T1, T2> operator+(pair<T1, T2> a, pair<T1, T2> b) {
  a.first += b.first;
  a.second += b.second;
  return a;
}
template <class T1, class T2>
pair<T1, T2> operator-(pair<T1, T2> a, pair<T1, T2> b) {
  a.first -= b.first;
  a.second -= b.second;
  return a;
}
template <class T1, class T2>
void operator+=(pair<T1, T2>& a, pair<T1, T2> b) {
  a.first += b.first;
  a.second += b.second;
}
template <class T1, class T2>
void operator-=(pair<T1, T2>& a, pair<T1, T2> b) {
  a.first -= b.first;
  a.second -= b.second;
}
template <class T>
vector<T> operator+(vector<T> a, vector<T> b) {
  a.insert(a.end(), b.begin(), b.end());
  return a;
}
const int INF = 1e9 + 1;
const int mod = 1e9 + 7;
int cnt = 0;
vector<vector<vector<pair<int, int>>>> gr;
vector<vector<int>> used;
bitset<4> f(int x) {
  bitset<4> res;
  int i = 3;
  while (x) {
    res[i] = x % 2;
    x /= 2;
    i--;
  }
  return res;
}
void dfs(int u, int v) {
  cnt++;
  used[u][v] = 1;
  for (auto buf : gr[u][v]) {
    int w = buf.first, x = buf.second;
    if (!used[w][x]) {
      dfs(w, x);
    }
  }
}
signed main() {
  {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  };
  int n, m, x;
  cin >> n >> m;
  vector<vector<bitset<4>>> a(n, (vector<bitset<4>>(m)));
  gr = vector<vector<vector<pair<int, int>>>>(
      n, vector<vector<pair<int, int>>>(m));
  used = vector<vector<int>>(n, vector<int>(m, 0));
  for (int i = 0; i < (n); i++) {
    for (int j = 0; j < (m); j++) {
      cin >> x;
      a[i][j] = f(x);
      if (!a[i][j][0]) {
        gr[i][j].push_back({i - 1, j});
      }
      if (!a[i][j][1]) {
        gr[i][j].push_back({i, j + 1});
      }
      if (!a[i][j][2]) {
        gr[i][j].push_back({i + 1, j});
      }
      if (!a[i][j][3]) {
        gr[i][j].push_back({i, j - 1});
      }
    }
  }
  vector<int> res;
  for (int u = 0; u < n; u++) {
    for (int v = 0; v < m; v++) {
      cnt = 0;
      if (!used[u][v]) {
        dfs(u, v);
        res.push_back(-cnt);
      }
    }
  }
  sort(res.begin(), res.end());
  for (auto t : res) {
    cout << -t << ' ';
  }
}
