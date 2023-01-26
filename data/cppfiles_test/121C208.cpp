#include <bits/stdc++.h>
using namespace std;
template <class T, class V>
T power(T t, V v) {
  T second = 1;
  while (v--) second *= t;
  return second;
}
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
  cerr << " ";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  int n = v.size();
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    n--;
    cerr << (n ? ", " : " ");
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
  int n = v.size();
  cerr << "{ ";
  for (auto p : v) {
    cerr << "[";
    _print(p.first);
    cerr << "]=";
    _print(p.second);
    n--;
    cerr << (n ? ", " : " ");
  }
  cerr << "}";
}
void go() {
  int n;
  cin >> n;
  string a;
  string b;
  cin >> a >> b;
  int sz = 0, so = 0, nsz = 0, nso = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) {
      if (a[i] == '0')
        sz++;
      else
        so++;
    } else if (a[i] == '0')
      nsz++;
    else
      nso++;
  }
  int N = 100000000;
  int ans = N;
  if (so - sz == 1) ans = min(ans, so + sz);
  if (nsz == nso) ans = min(ans, nsz + nso);
  if (ans == N)
    cout << "-1\n";
  else
    cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    go();
  }
  return 0;
}
