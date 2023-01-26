#include <bits/stdc++.h>
using namespace std;
template <typename T>
T get_rand(T l, T r) {
  random_device rd;
  mt19937 gen(rd());
  return uniform_int_distribution<T>(l, r)(gen);
}
#pragma GCC optimize("-Ofast")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx2,mmx,fma,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("03")
#pragma optimize("g", on)
template <typename T>
T lcm(T a, T b) {
  return a * (b / gcd(a, b));
}
template <class A>
void read(vector<A>& v);
template <class A, size_t S>
void read(array<A, S>& a);
template <class T>
void read(T& x) {
  cin >> x;
}
void read(double& d) {
  string t;
  read(t);
  d = stod(t);
}
void read(long double& d) {
  string t;
  read(t);
  d = stold(t);
}
template <class H, class... T>
void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A>
void read(vector<A>& x) {
  for (auto& a : x) read(a);
}
template <class A, size_t S>
void read(array<A, S>& x) {
  for (auto& a : x) read(a);
}
string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(vector<bool> v) {
  string res;
  for (int i = 0; i < (int)v.size(); ++i) res += char('0' + v[i]);
  return res;
}
template <size_t S>
string to_string(bitset<S> b) {
  string res;
  for (int i = 0; i < S; ++i) res += char('0' + b[i]);
  return res;
}
template <class T>
string to_string(T v) {
  bool f = 1;
  string res;
  for (auto x : v) {
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
void write(const H& h, const T&... t) {
  write(h);
  write(t...);
}
void print() { write("\n"); }
template <class H, class... T>
void print(const H& h, const T&... t) {
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
const int MOD = 1e9 + 7;
const int N = 3e6 + 5;
const long long INF = 9e18;
const int M = 3e3 + 5;
const double long pi = 3.1415926535897932384626433832795;
int a[M][M];
char ans[M][M];
void solve() {
  int n, m, k;
  read(n, m, k);
  for (int i = 1; i <= n + 5; ++i) {
    for (int j = 1; j <= m + 5; ++j) a[i][j] = 0;
  }
  int pos = 1;
  int x = n * m - k * 2;
  x /= 2;
  if (m % 2) {
    for (int i = 1; i < n; i += 2) {
      a[i][1] = a[i + 1][1] = pos++;
    }
    x -= n / 2;
    if (x < 0) {
      print("NO");
      return;
    }
    if (k % 2 || x % 2) {
      print("NO");
      return;
    }
  } else if (n % 2) {
    for (int i = 1; i < m; i += 2) {
      a[1][i] = a[1][i + 1] = pos++;
    }
    if (n % 2) k -= m / 2;
    if (k < 0) {
      print("NO");
      return;
    }
    if (k % 2 || x % 2) {
      print("NO");
      return;
    }
  } else {
    if (k % 2 || x % 2) {
      print("NO");
      return;
    }
  }
  print("YES");
  for (int i = 1; i <= n; ++i) {
    for (int j = 2; j < m && k; j += 2) {
      a[i][j] = a[i][j + 1] = pos++;
      --k;
    }
    if (!k) break;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 2; j <= m; ++j) {
      if (!a[i][j] && !a[i + 1][j]) a[i][j] = a[i + 1][j] = pos++;
    }
  }
  ans[1][1] = 'a';
  if (a[1][2] == a[1][1])
    ans[1][2] = 'a';
  else
    ans[2][1] = 'a';
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!ans[i][j]) {
      } else
        continue;
      vector<bool> was(26);
      if (a[i][j] == a[i + 1][j]) {
        if (ans[i - 1][j]) was[ans[i - 1][j] - 'a'] = 1;
        if (ans[i][j + 1]) was[ans[i][j + 1] - 'a'] = 1;
        if (ans[i + 2][j]) was[ans[i + 2][j] - 'a'] = 1;
        if (ans[i][j - 1]) was[ans[i][j - 1] - 'a'] = 1;
        if (ans[i + 1][j - 1]) was[ans[i + 1][j - 1] - 'a'] = 1;
        if (ans[i + 1][j + 1]) was[ans[i + 1][j + 1] - 'a'] = 1;
        int x;
        for (int l = 0; l < 26; ++l) {
          if (!was[l]) {
            x = l;
          }
        }
        ans[i][j] = char(x + 'a'), ans[i + 1][j] = char(x + 'a');
      } else {
        if (ans[i - 1][j]) was[ans[i - 1][j] - 'a'] = 1;
        if (ans[i][j + 2]) was[ans[i][j + 2] - 'a'] = 1;
        if (ans[i + 1][j]) was[ans[i + 1][j] - 'a'] = 1;
        if (ans[i][j - 1]) was[ans[i][j - 1] - 'a'] = 1;
        if (ans[i - 1][j + 1]) was[ans[i - 1][j + 1] - 'a'] = 1;
        if (ans[i + 1][j + 1]) was[ans[i + 1][j + 1] - 'a'] = 1;
        int x;
        for (int l = 0; l < 26; ++l) {
          if (!was[l]) {
            x = l;
          }
        }
        ans[i][j] = char(x + 'a'), ans[i][j + 1] = char(x + 'a');
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) cout << ans[i][j];
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  read(t);
  for (int i = 1; i <= t; ++i) {
    solve();
  }
  return 0;
}
