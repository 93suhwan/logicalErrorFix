#include <bits/stdc++.h>
using namespace std;
void _print(long long int t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
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
long long int add(long long int x, long long int y) {
  long long int ans = x + y;
  return (ans >= 1000000007 ? ans - 1000000007 : ans);
}
long long int sub(long long int x, long long int y) {
  long long int ans = x - y;
  return (ans < 0 ? ans + 1000000007 : ans);
}
long long int mul(long long int x, long long int y) {
  long long int ans = x * y;
  return (ans >= 1000000007 ? ans % 1000000007 : ans);
}
void solve() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(NULL));
  long long int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int x = 0, y = 0, x1 = 0, y1 = 0;
    for (long long int i = 0; i < n; ++i)
      if (a[i] == b[i]) {
        x++;
        if (a[i] == '1') x1++;
      } else {
        y++;
        if (a[i] == '1') y1++;
      }
    int ans = INT_MAX;
    if (x % 2 != 0 && (x + 1) / 2 == x1) ans = x;
    if (y % 2 == 0 && (y / 2) == y1) ans = min(ans, y);
    if (ans == INT_MAX)
      cout << -1 << '\n';
    else
      cout << ans << '\n';
  }
  return 0;
}
