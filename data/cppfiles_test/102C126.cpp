#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
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
void solve() {
  int t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    long long l = 0, r = 0, u = 0, d = 0;
    long long x = 0, y = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'L') {
        x--;
      } else if (s[i] == 'R') {
        x++;
      } else if (s[i] == 'U') {
        y++;
      } else {
        y--;
      }
      if ((max(r, x) - min(l, x)) + 1 > m || (max(u, y) - min(d, y)) + 1 > n) {
        break;
      }
      l = min(l, x);
      r = max(r, x);
      u = max(u, y);
      d = min(d, y);
    }
    cout << 1 + u << " " << 1 - l << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
