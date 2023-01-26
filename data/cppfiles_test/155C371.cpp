#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
long long myceil(long long a, long long b) {
  if (a % b == 0)
    return a / b;
  else
    return a / b + 1;
}
bool isPerSquare(long double a) {
  if (a < 0) return false;
  long long sr = sqrt(a);
  return (sr * sr == a);
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
const long long MAXLEN1 = 200002, MAXLEN2 = 200002;
vector<long long> arr1(MAXLEN1);
vector<long long> arr2(MAXLEN2);
vector<vector<long long>> arr2D(1001, vector<long long>(1001));
void solve() {
  long long n, m, a, b, c, d;
  string s;
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> arr1[i];
  cin >> s;
  vector<pair<int, int>> zeros, ones;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0')
      zeros.push_back({arr1[i], i});
    else
      ones.push_back({arr1[i], i});
  }
  sort(zeros.begin(), zeros.end());
  sort(ones.begin(), ones.end());
  int cnt = 1;
  map<int, int> ans;
  for (auto i : zeros) {
    ans[i.second] = cnt;
    cnt++;
  }
  for (auto i : ones) {
    ans[i.second] = cnt;
    cnt++;
  }
  for (long long i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
