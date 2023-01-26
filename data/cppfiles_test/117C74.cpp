#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
long long int INF = 1e9 + 5;
long long int mod = 998244353;
void _print(long long int t) { cerr << t; }
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
vector<pair<long long int, long long int> > dir = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool good(long long int x, long long int y, vector<string> &a) {
  long long int n = a.size(), m = a[0].length();
  if (x < 0 || x == n || y < 0 || y == m || a[x][y] != '.') {
    return 0;
  }
  return 1;
}
bool poss(long long int x, long long int y, vector<string> &a) {
  long long int n = a.size(), m = a[0].length(), curr = 0;
  for (auto &p : dir) {
    long long int x1 = x + p.first, y1 = y + p.second;
    if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && a[x1][y1] == '.') {
      curr++;
    }
  }
  return curr <= 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    long long int startx, starty;
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < m; j++) {
        if (a[i][j] == 'L') {
          startx = i;
          starty = j;
        }
      }
    }
    queue<pair<long long int, long long int> > q;
    for (auto &x : dir) {
      q.push({startx + x.first, starty + x.second});
    }
    while (!q.empty()) {
      pair<long long int, long long int> node = q.front();
      q.pop();
      if (!good(node.first, node.second, a)) {
        continue;
      }
      if (poss(node.first, node.second, a)) {
        a[node.first][node.second] = '+';
        for (auto &x : dir) {
          q.push({node.first + x.first, node.second + x.second});
        }
      }
    }
    for (auto &x : a) {
      cout << x << "\n";
    }
  }
}
