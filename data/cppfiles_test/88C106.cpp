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
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
void precision(int a) { cout << setprecision(a) << fixed; }
bool comp(pair<long long, long long> &p1, pair<long long, long long> &p2) {
  if (p1.second <= p2.second) return true;
  return false;
}
long long myfunc(vector<pair<long long, long long>> vp, long long m) {
  sort(vp.begin(), vp.end(), comp);
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < i; j++) {
      if (vp[j].first < vp[i].first) ans++;
    }
  }
  return ans;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> v(m * n);
  long long ans = 0;
  vector<pair<long long, long long>> vp(n * m);
  for (int i = 0; i < n * m; i++) {
    cin >> v[i];
    vp[i] = {v[i], i};
  }
  sort(vp.begin(), vp.end());
  ;
  int p = 0, q = m;
  for (int i = 0; i < n; i++) {
    vector<pair<long long, long long>> vec(vp.begin() + p, vp.begin() + q);
    ans += myfunc(vec, m);
    p += m;
    q += m;
  }
  cout << ans << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long test;
  cin >> test;
  while (test--) solve();
}
