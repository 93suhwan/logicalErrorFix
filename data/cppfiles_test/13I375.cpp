#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &x) {
  cin >> x;
}
template <class H, class T>
void read(pair<H, T> &p) {
  cin >> p.first >> p.second;
}
template <class T, size_t S>
void read(array<T, S> &a) {
  for (T &i : a) read(i);
}
template <class T>
void read(vector<T> &v) {
  for (T &i : v) read(i);
}
template <class H, class... T>
void read(H &h, T &...t) {
  read(h);
  read(t...);
}
template <class H, class T>
ostream &operator<<(ostream &o, pair<H, T> &p) {
  o << p.first << " " << p.second;
  return o;
}
template <class T, size_t S>
ostream &operator<<(ostream &o, array<T, S> &a) {
  string s;
  for (T i : a) o << s << i, s = " ";
  return o;
}
template <class T>
ostream &operator<<(ostream &o, vector<T> &v) {
  string s;
  for (T i : v) o << s << i, s = " ";
  return o;
}
template <class T>
void write(T x) {
  cout << x;
}
template <class H, class... T>
void write(const H &h, const T &...t) {
  write(h);
  write(t...);
}
void print() { write('\n'); }
template <class H, class... T>
void print(const H &h, const T &...t) {
  write(h);
  if (sizeof...(t)) write(' ');
  print(t...);
}
template <class T>
bool ckmin(T &a, const T b) {
  return (b < a) ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T &a, const T b) {
  return (a < b) ? a = b, 1 : 0;
}
using ll = long long;
void solve() {
  int n, m, k;
  read(n, m, k);
  if (m == 2) {
    if (k != n) return void(print("NO"));
    print("YES");
    for (int i = 0; i < n; ++i) print((i & 1) ? "aa" : "bb");
    return;
  }
  vector<vector<char>> g(n, vector<char>(m, '?'));
  if (n & 1) {
    if (k < m / 2) return void(print("NO"));
    assert(m % 2 == 0);
    for (int i = 0; i < m / 2; ++i)
      g[0][i * 2] = g[0][i * 2 + 1] = char('a' + (i & 1));
    k -= m / 2;
  }
  if (k & 1) return void(print("NO"));
  for (int i = 0; i < m / 2; ++i) {
    for (int j = (n & 1); j < n; ++j) {
      if (!k) break;
      --k;
      g[j][i * 2] = g[j][i * 2 + 1] = char('a' + ((j & 1) ^ (i & 1)));
    }
    if (!k) break;
  }
  if (k) return void(print("NO"));
  int add = (n & 1);
  for (int i = 0; i < n / 2; ++i) {
    for (int j = 0; j < m; ++j) {
      if (g[i * 2 + add][j] == '?')
        g[i * 2 + add][j] = g[i * 2 + add + 1][j] =
            char('y' + ((j & 1) ^ (i & 1)));
    }
  }
  print("YES");
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) write(g[i][j]);
    print();
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  read(t);
  while (t--) solve();
}
