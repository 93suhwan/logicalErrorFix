#include <bits/stdc++.h>
long long cnt;
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
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
  long long W, H;
  cin >> W >> H;
  long long x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long w, h;
  cin >> w >> h;
  long long ans = INT_MAX;
  if (((H - y2) >= h) or (y1 >= h) or ((W - x2) >= w) or (x1 >= w)) {
    cout << 0 << "\n";
    return;
  }
  if ((w + (x2 - x1)) <= W) {
    if (w - x1 >= 0) {
      ans = min(ans, w - x1);
    }
    if (w - (W - x2) >= 0) {
      ans = min(ans, w - (W - x2));
    }
  }
  if (h + (y2 - y1) <= H) {
    if (h - y1 >= 0) {
      ans = min(ans, h - y1);
    }
    if (h - (H - y2) >= 0) {
      ans = min(ans, h - (H - y2));
    }
  }
  if (ans == INT_MAX) {
    cout << -1 << "\n";
    return;
  }
  cout << setprecision(6) << ans << "\n";
}
int main() {
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
}
