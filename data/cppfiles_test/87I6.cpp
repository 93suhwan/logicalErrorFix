#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cout << t; }
void _print(int t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(long double t) { cout << t; }
void _print(double t) { cout << t; }
void _print(unsigned long long t) { cout << t; }
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
  cout << "{";
  _print(p.first);
  cout << ",";
  _print(p.second);
  cout << "}";
}
template <class T>
void _print(vector<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(set<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T>
void _print(multiset<T> v) {
  cout << "[ ";
  for (T i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cout << "[ ";
  for (auto i : v) {
    _print(i);
    cout << " ";
  }
  cout << "]";
}
bool cmp(pair<int, int> &a, pair<int, int> &b) { return a.first > b.first; }
void solution() {
  int n;
  cin >> n;
  vector<pair<int, int> > m;
  for (int i = 0; i < n; i++) {
    int z;
    cin >> z;
    m.push_back(make_pair(z, i + 1));
  }
  sort((m).begin(), (m).end(), cmp);
  cout << abs(m[0].first - m[0].second) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}
