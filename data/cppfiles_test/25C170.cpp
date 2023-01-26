#include <bits/stdc++.h>
using namespace std;
template <class A>
void read(vector<A> &v);
template <class T>
void read(T &x) {
  cin >> x;
}
void read(double &d) { cin >> d; }
void read(long double &d) { cin >> d; }
template <class H, class... T>
void read(H &h, T &...t) {
  read(h);
  read(t...);
}
template <class A>
void read(vector<A> &x) {
  for (auto &a : x) read(a);
}
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "YES" : "NO"; }
string to_string(const char *s) { return string(s); }
string to_string(vector<bool> v) {
  string res;
  for (int i = 0; i < (int)(v).size(); i++) res += char('0' + v[i]);
  return res;
}
template <class T>
string to_string(T v) {
  bool f = 1;
  string res;
  for (auto &x : v) {
    if (!f) res += ' ';
    f = 0;
    res += to_string(x);
  }
  return res;
}
template <class A>
void write(A x) {
  cout << to_string(x);
}
template <class H, class... T>
void write(const H &h, const T &...t) {
  write(h);
  write(t...);
}
void print() { write("\n"); }
template <class H, class... T>
void print(const H &h, const T &...t) {
  write(h);
  if (sizeof...(t)) write(' ');
  print(t...);
}
void DBG() { cerr << "]" << endl; }
template <class H, class... T>
void DBG(H h, T... t) {
  cerr << to_string(h);
  if (sizeof...(t)) cerr << ", ";
  DBG(t...);
}
void solve() {
  string s, t;
  read(s, t);
  if (s == t) {
    print("YES");
    return;
  }
  int n = s.length(), m = t.length();
  for (int i = 0; i < n; i++) {
    if (s[i] != t[0]) continue;
    int k = i;
    int j = 0;
    while (k < n && j < m && s[k] == t[j]) {
      if (k - 2 >= 0 && s[k] == t[j]) {
        int a = k - 2, b = j;
        while (a >= 0 && j < m && s[a] == t[b]) {
          a--;
          b++;
        }
        if (b == m) {
          print("YES");
          return;
        }
      }
      k++, j++;
    }
    k -= 2;
    while (k >= 0 && j < m && s[k] == t[j]) {
      j++;
      k--;
    }
    if (j == m) {
      print("YES");
      return;
    }
  }
  print("NO");
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  read(t);
  for (int i = 0; i < t; i++) {
    solve();
  }
}
