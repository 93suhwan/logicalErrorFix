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
    int m = 0, tu = 0, w = 0, th = 0, f = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> a[i][j];
        if (a[i][j] == 1)
          if (j == 0)
            m++;
          else if (j == 1)
            tu++;
          else if (j == 2)
            w++;
          else if (j == 3)
            th++;
          else
            f++;
      }
    }
    int count = 0;
    int temp = n / 2;
    if (m >= temp) count += m;
    if (tu >= temp) count += tu;
    if (w >= temp) count += w;
    if (th >= temp) count += th;
    if (f >= temp) count += f;
    ;
    if (count > n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
