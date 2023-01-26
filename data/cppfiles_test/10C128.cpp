#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
const long long MOD = 998244353;
const double EPS = 1e-8;
const double PI = acos(-1.0);
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
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> ind(n + 1);
  for (int i = 0; i < n; ++i) {
    int u;
    cin >> u;
    if ((long long)ind[u].size() >= k) continue;
    ind[u].push_back(i);
  }
  int cnt = 0;
  for (int i = 0; i <= n; ++i) {
    cnt += (long long)ind[i].size();
  }
  cnt /= k;
  cnt *= k;
  int cntp = cnt / k;
  int c = 0;
  vector<int> ans(n, -1);
  for (auto v : ind) {
    for (auto u : v) {
      if (cnt == 0) continue;
      ans[u] = c++;
      c %= k;
      cnt--;
    }
  }
  vector<int> f(k);
  for (int i = 0; i < n; ++i) {
    if (ans[i] >= 0) f[ans[i]]++;
  }
  for (int i = 0; i < k; ++i) assert(f[i] == cntp);
  for (int i = 0; i < n; ++i) cout << ans[i] + 1 << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
