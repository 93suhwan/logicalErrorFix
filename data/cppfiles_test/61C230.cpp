#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
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
long long po(long long a, long long b, long long m) {
  long long t = 1;
  while (b > 0) {
    if (b % 2 != 0) {
      t = (t * a) % m;
    }
    a = (a * a) % m;
    b = b / 2;
  }
  return t;
}
long long inv(long long a, long long m) { return po(a, m - 2, m); }
bool sortbysec(const pair<char, long long> &a, const pair<char, long long> &b) {
  return (a.second < b.second);
}
long long get(long long n) {
  long long ans = 1;
  for (long long i = 2; i <= n; i++)
    ans = (ans % 1000000007 * i % 1000000007) % 1000000007;
  return ans % 1000000007;
}
long long nPr(long long n, long long r) {
  return get(n) * inv(get(n - r), 1000000007);
}
long long modularExponentiation(long long x, long long n) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % 1000000007;
    x = (x * x) % 1000000007;
    n = n / 2;
  }
  return result;
}
void solve() {
  long long i, j, flag = 0;
  long long n;
  cin >> n;
  map<long long, long long> M, N;
  map<pair<long long, long long>, long long> x;
  vector<pair<long long, long long>> v;
  for (i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    v.push_back({a, b});
    M[a]++;
    N[b]++;
    x[{a, b}]++;
  }
  long long sum = (n * (n - 1) * (n - 2)) / 6;
  ;
  for (i = 0; i < n; i++) {
    if (M[v[i].first] >= 2 && N[v[i].second] >= 2) {
      sum -= (M[v[i].first] - 1) * (N[v[i].second] - 1);
    }
  }
  cout << sum << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
