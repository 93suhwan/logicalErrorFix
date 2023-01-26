#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  cin >> x;
}
template <typename T, typename T0>
void read(T &x, T0 &y) {
  cin >> x >> y;
}
template <typename T, typename T0, typename T1>
void read(T &x, T0 &y, T1 &z) {
  cin >> x >> y >> z;
}
template <typename T, typename T0, typename T1, typename T2>
void read(T &x, T0 &y, T1 &z, T2 &w) {
  cin >> x >> y >> z >> w;
}
template <typename T, typename T0>
void read(pair<T, T0> &p) {
  cin >> p.first >> p.second;
}
template <typename T>
void read(vector<T> &oneD, long long int n) {
  for (long long int(i) = 0; (i) < (n); ++(i)) {
    long long int x;
    read(x);
    oneD.push_back(x);
  }
}
template <typename T>
void read(T oneD[], long long int n) {
  for (long long int i = 0; i < n; i++) {
    read(oneD[i]);
  }
}
template <typename T>
void write(T &x) {
  cout << x << " ";
}
template <typename T>
void wrtline(T &x) {
  cout << x << "\n";
}
template <typename T, typename T0>
void write(T &x, T0 &y) {
  cout << x << " " << y << "\n";
}
template <typename T, typename T0, typename T1>
void write(T &x, T0 &y, T1 &z) {
  cout << x << " " << y << " " << z << "\n";
}
template <typename T, typename T0, typename T1, typename T2>
void write(T &x, T0 &y, T1 &z, T2 &w) {
  cout << x << " " << y << " " << z << " " << w << "\n";
}
template <typename T, typename T0>
void write(pair<T, T0> &p) {
  write(p.first);
  write(p.second);
  cout << "\n";
}
template <typename T>
void write(vector<T> &oneD, long long int n) {
  for (long long int i = 0; i < n; i++) {
    cout << oneD[i] << " ";
  }
  cout << "\n";
}
template <typename T>
void write(T oneD[], int &n) {
  for (long long int i = 0; i < n; i++) {
    write(oneD[i]);
  }
  cout << "\n";
}
template <typename T, typename T0>
void write(map<T, T0> &mpp) {
  for (auto it : mpp) {
    write(it.first);
    cout << ": ";
    write(it.second);
    cout << "\n";
  }
  cout << "\n";
}
template <typename T>
void write(vector<vector<T>> &rc, T &n, T &m) {
  for (long long int(i) = 0; (i) < (n); ++(i)) {
    for (long long int(j) = 0; (j) < (m); ++(j)) {
      cout << rc[i][j] << " ";
    }
    cout << "\n";
  }
}
template <typename T>
void _print(T &t) {
  cerr << t;
}
template <class T, class V>
void _print(pair<T, V> &p);
template <class T>
void _print(vector<T> &v);
template <class T>
void _print(set<T> &v);
template <class T, class V>
void _print(map<T, V> &v);
template <class T>
void _print(multiset<T> &v);
template <class T, class V>
void _print(pair<T, V> &p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> &v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> &v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> &v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> &v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long int x;
bool compareFn(pair<string, long long int> &a, pair<string, long long int> &b) {
  if (x % 2 == 0)
    return a.first[x] < b.first[x];
  else
    return a.first[x] > b.first[x];
}
void solve() {
  long long int n, m;
  read(n, m);
  vector<pair<string, long long int>> s;
  for (long long int(i) = 0; (i) < (n); ++(i)) {
    string t;
    read(t);
    s.push_back({t, i + 1});
  }
  x = 0;
  sort((s).begin(), (s).end(), compareFn);
  x++;
  while (x < m) {
    long long int i = 0, j = 0;
    while (j != n) {
      while (j < n - 1 and s[j].first[x - 1] == s[j + 1].first[x - 1]) j++;
      j++;
      sort(s.begin() + i, s.begin() + j, compareFn);
      i = j;
    }
    x++;
  }
  for (long long int(i) = 0; (i) < (n); ++(i)) cout << s[i].second << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
