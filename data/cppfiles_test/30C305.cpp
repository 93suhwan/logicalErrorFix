#include <bits/stdc++.h>
using namespace std;
long long inf = 10000000000;
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
const int mod = 1e9 + 7;
void precision(int a) { cout << fixed << setprecision(a); }
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = INT_MAX;
  int cnt = 0;
  for (char ch = 'a'; ch <= 'z'; ++ch) {
    int l = 0;
    int r = s.length() - 1;
    cnt = 0;
    while (l <= r) {
      if (s[l] == s[r]) {
        l++;
        r--;
      } else {
        if (ch == char(s[l])) {
          cnt++;
          l++;
        } else if (ch == char(s[r])) {
          cnt++;
          r--;
        } else {
          cnt = INT_MAX;
          break;
        }
      }
    };
    ans = min(ans, cnt);
    ;
  }
  cout << ((ans == INT_MAX) ? -1 : ans) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  cerr << "\n" << (float)clock() / CLOCKS_PER_SEC * 1000 << "ms" << endl;
}
