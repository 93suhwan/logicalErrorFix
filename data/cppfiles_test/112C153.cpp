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
void init_code() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void func() {
  int a, b, c, m;
  cin >> a >> b >> c >> m;
  vector<int> ac;
  ac.push_back(a);
  ac.push_back(b);
  ac.push_back(c);
  sort(ac.begin(), ac.end());
  if (m > ((a ? a - 1 : a) + (b ? b - 1 : b) + (c ? c - 1 : c)) ||
      m < (ac[2] - 1 - (ac[1] + ac[0]))) {
    cout << "no";
  } else {
    cout << "yes";
  }
  cout << "\n";
}
int main() {
  init_code();
  double start1 = (double)clock();
  int t = 1;
  cin >> t;
  while (t--) func();
  double stop1 = (double)clock();
  double duration = (stop1 - start1) / CLOCKS_PER_SEC;
}
