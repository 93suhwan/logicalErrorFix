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
  int n, m;
  read(n, m);
  vector<int> a(n), cnt(n);
  read(a);
  for (int &i : a) --i;
  for (int i = 0; i < n; ++i) {
    int here;
    if (a[i] > i)
      here = n + i - a[i];
    else
      here = i - a[i];
    ++cnt[here];
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i)
    if (cnt[i] + m * 2 >= n) ans.push_back(i);
  write(ans.size());
  for (int i : ans) write(' ', i);
  print();
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  read(t);
  while (t--) solve();
}
