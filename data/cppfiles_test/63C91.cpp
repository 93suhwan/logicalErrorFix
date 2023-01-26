#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(bool t) { cerr << t; }
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
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
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
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long long LINF = LLONG_MAX;
long long parent[1001], rk[10001];
void make_set(long long v) {
  parent[v] = v;
  rk[v] = 0;
}
long long find_set(long long v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(long long a, long long b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (rk[a] < rk[b]) swap(a, b);
    parent[b] = a;
    if (rk[a] == rk[b]) rk[a]++;
  }
}
bool check(long long a, long long b) { return find_set(a) == find_set(b); }
long long parent2[1001], rk2[10001];
void make_set2(long long v) {
  parent2[v] = v;
  rk2[v] = 0;
}
long long find_set2(long long v) {
  if (v == parent2[v]) return v;
  return parent2[v] = find_set2(parent2[v]);
}
void union_sets2(long long a, long long b) {
  a = find_set2(a);
  b = find_set2(b);
  if (a != b) {
    if (rk2[a] < rk2[b]) swap(a, b);
    parent2[b] = a;
    if (rk2[a] == rk2[b]) rk2[a]++;
  }
}
bool check2(long long a, long long b) { return find_set2(a) == find_set2(b); }
void solve() {
  long long n, m1, m2;
  cin >> n >> m1 >> m2;
  vector<long long> v(n + 1, 0);
  vector<long long> d1(n + 1), d2(n + 1);
  for (long long i = 1; i <= n; i++) make_set(i);
  for (long long i = 1; i <= n; i++) make_set2(i);
  for (long long i = 0; i < m1; i++) {
    long long x, y;
    cin >> x >> y;
    union_sets(x, y);
  }
  for (long long i = 0; i < m2; i++) {
    long long x, y;
    cin >> x >> y;
    union_sets2(x, y);
  }
  vector<pair<long long, long long>> p;
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      if (!check(i, j) && !check2(i, j)) {
        union_sets(i, j);
        union_sets2(i, j);
        p.push_back({i, j});
      }
    }
  }
  cout << p.size() << ("\n");
  for (auto d : p) cout << d.first << " " << d.second << ("\n");
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 1, count = 1;
  while (t--) {
    solve();
  }
  return 0;
}
