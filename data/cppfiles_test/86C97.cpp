#include <bits/stdc++.h>
using namespace std;
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
long long int powe(long long int x, long long int y,
                   long long int p = 1000000007) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int inverse_modulo(long long int a, long long int p = 1000000007) {
  return powe(a, p - 2, p);
}
template <class T, class vv>
void _print(pair<T, vv> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class vv>
void _print(map<T, vv> v);
template <class T>
void _print(multiset<T> v);
template <class T, class vv>
void _print(pair<T, vv> p) {
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
template <class T, class vv>
void _print(map<T, vv> v) {
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
  string a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = 0; i < (int)n; i++) {
    if (abs(a[i] - b[i]) == 1) {
      ans += 2;
    } else if (i + 1 < n && abs(a[i + 1] - b[i + 1]) == 0 && a[i] != a[i + 1]) {
      ans += 2;
      i++;
    } else if (a[i] == '0') {
      ans += 1;
    }
  }
  cout << ans << "\n";
}
int main() {
  freopen("Error.txt", "w", stderr);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
