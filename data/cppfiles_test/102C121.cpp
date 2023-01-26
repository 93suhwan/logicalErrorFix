#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void _print(long long n) { cerr << n; }
void _print(int n) { cerr << n; }
void _print(string n) { cerr << n; }
void _print(char n) { cerr << n; }
void _print(long double n) { cerr << n; }
void _print(double n) { cerr << n; }
void _print(unsigned long long n) { cerr << n; }
void _print(bool n) { cerr << n; }
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
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
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
template <class T>
void _print(unordered_set<T> s2) {
  cerr << "[";
  for (T i : s2) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T1, class T2>
void _print(unordered_map<T1, T2> m2) {
  cerr << "[";
  for (auto i : m2) {
    cerr << "(";
    _print(i.first);
    cerr << " , ";
    _print(i.second);
    cerr << ")";
  }
  cerr << "]";
}
const long long MOD = 1000000007;
void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int left = 0, right = 0, up = 0, down = 0, x = 0, y = 0;
  int xcoord = 1, ycoord = 1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'U') {
      x--;
    }
    if (s[i] == 'D') {
      x++;
    }
    if (s[i] == 'L') {
      y--;
    }
    if (s[i] == 'R') {
      y++;
    }
    left = min(left, y);
    up = min(up, x);
    right = max(right, y);
    down = max(down, x);
    if (right - left >= m || down - up >= n) {
      break;
    }
    xcoord = n - down;
    ycoord = m - right;
  }
  cout << xcoord << " " << ycoord << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
