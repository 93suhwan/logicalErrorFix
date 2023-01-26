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
void INIT() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  INIT();
  long long t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n][5];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> a[i][j];
      }
    }
    bool found = false;
    for (int i = 0; i < 5; i++) {
      for (int j = i + 1; j < 5; j++) {
        int x = 0, y = 0, z = 0;
        for (int k = 0; k < n; k++) {
          if (a[k][i] && a[k][j])
            z++;
          else if (a[k][i])
            x++;
          else if (a[k][j])
            y++;
        };
        ;
        ;
        if (x + y + z == n && x <= n / 2 && y <= n / 2) found = true;
      }
    }
    if (found)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
