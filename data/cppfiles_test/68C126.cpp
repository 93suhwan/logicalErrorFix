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
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << " " << 1 << endl;
    return;
  }
  int cnt = 0;
  int temp = 1;
  int ans = 0;
  for (int i = 1; i < 100000; i++) {
    int temp2 = 0;
    temp = temp + 2 * i;
    temp2 = temp - i;
    cnt++;
    if (n <= temp2 + 2 * cnt and n >= temp2) {
      ans = n - temp;
      break;
    }
  }
  int x = 0, y = 0;
  if (ans < 0) {
    x = cnt;
    y = cnt - abs(ans);
  } else {
    x = cnt - abs(ans);
    y = cnt;
  }
  cout << y + 1 << " " << x + 1 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
