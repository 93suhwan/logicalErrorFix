#include <bits/stdc++.h>
using namespace std;
const long long SZ = 1e5 + 7;
const long long inf = 1e18;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long PI = 3.1415926535897932384;
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{ ";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "} ";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "] ";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "] ";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
int expo(int a, int b, int mod) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
void google(int t) { cout << "Case # " << t << ": "; }
int mod_add(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
int mod_mul(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
int mod_sub(int a, int b, int m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int up = 0, left = 0;
  int min_up = 0, min_left = 0, max_up = 0, max_left = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'U') {
      up++;
      if (max(max_up, up) - min_up >= n) break;
      max_up = max(max_up, up);
    } else if (s[i] == 'D') {
      up--;
      if (max_up - min(min_up, up) >= n) break;
      min_up = min(min_up, up);
    } else if (s[i] == 'L') {
      left++;
      if (max(max_left, left) - min_left >= m) break;
      max_left = max(max_left, left);
    } else if (s[i] == 'R') {
      left--;
      if (max_left - min(min_left, left) >= m) break;
      min_left = min(min_left, left);
    }
  }
  cout << 1 + max_up << " " << 1 + max_left << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
