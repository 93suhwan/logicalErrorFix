#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T, class second>
ostream &operator<<(ostream &os, const pair<T, second> &v) {
  os << v.first << ' ' << v.second;
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for (T i : v) os << i << ' ';
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &v) {
  for (T i : v) os << i << ' ';
  return os;
}
template <class T, class second>
ostream &operator<<(ostream &os, const map<T, second> &v) {
  for (auto i : v) os << '(' << i.first << "," << i.second << ')' << ' ';
  return os;
}
template <class T, class second>
ostream &operator<<(ostream &os, const unordered_map<T, second> &v) {
  for (auto i : v) os << '(' << i.first << "," << i.second << ')' << ' ';
  return os;
}
long long m1(vector<vector<int> > &r, vector<vector<int> > &d,
             vector<vector<int> > &s, int x, int y, long long c, int f,
             int fl) {
  long long t = c;
  bool f2 = true;
  while (x < r.size() && y < r[0].size() && f2) {
    if (f == 1) {
      f--;
      x++;
      if (x < r.size() && s[x][y] == 0) {
        d[x][y] += fl * c;
        t += c;
      }
      if (x < r.size() && s[x][y] == 1) {
        f2 = false;
      }
    } else {
      f++;
      y++;
      if (y < r[0].size() && s[x][y] == 0) {
        t += c;
        r[x][y] += fl * c;
      }
      if (y < r[0].size() && s[x][y] == 1) {
        f2 = false;
      }
    }
  }
  return t;
}
void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  long long a = -1 * n * m;
  vector<vector<int> > s(n, vector<int>(m, 0));
  vector<vector<int> > r(n, vector<int>(m, 1)), d(n, vector<int>(m, 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j > 0) {
        r[i][j] += d[i][j - 1];
      }
      if (i > 0) {
        d[i][j] += r[i - 1][j];
      }
      a += r[i][j] + d[i][j];
    }
  }
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (s[x][y] == 0) {
      s[x][y] = 1;
      long long t = m1(r, d, s, x, y, r[x][y], 1, -1);
      t += m1(r, d, s, x, y, d[x][y], 0, -1);
      t--;
      a -= t;
      r[x][y] = 0;
      d[x][y] = 0;
    } else {
      s[x][y] = 0;
      r[x][y] = 1;
      d[x][y] = 1;
      if (x > 0) {
        d[x][y] += r[x - 1][y];
      }
      if (y > 0) {
        r[x][y] += d[x][y - 1];
      }
      long long t = m1(r, d, s, x, y, r[x][y], 1, 1);
      t += m1(r, d, s, x, y, d[x][y], 0, 1);
      t--;
      a += t;
    }
    cout << a;
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
