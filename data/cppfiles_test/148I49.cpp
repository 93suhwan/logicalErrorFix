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
  int w, h;
  cin >> w >> h;
  int k;
  cin >> k;
  vector<int> side1;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    side1.push_back(x);
  }
  cin >> k;
  vector<int> side2;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    side2.push_back(x);
  }
  cin >> k;
  vector<int> side3;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    side3.push_back(x);
  }
  cin >> k;
  vector<int> side4;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    side4.push_back(x);
  }
  int op1 = abs(side1[0] - side1[side1.size() - 1]) * h;
  int op2 = abs(side2[0] - side2[side2.size() - 1]) * h;
  int op3 = abs(side3[0] - side3[side3.size() - 1]) * w;
  int op4 = abs(side4[0] - side4[side4.size() - 1]) * w;
  int ans = max(op1, max(op2, max(op3, op4)));
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
