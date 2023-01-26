#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000000001;
const long long inf = 1e18 + 1;
const long long MOD = 1000000007;
template <class T>
void __print(T v);
template <class T>
void __print(vector<T> v);
template <class T>
void __print(set<T> v);
template <class T1, class T2>
void __print(map<T1, T2> mp);
template <class T1, class T2>
void __print(pair<T1, T2> p);
template <class T1, class T2>
void __print(unordered_map<T1, T2> mp);
template <class T>
void __print(T v) {
  cerr << v;
}
template <class T>
void __print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    __print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void __print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    __print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T1, class T2>
void __print(map<T1, T2> mp) {
  cerr << "[ ";
  for (auto i : mp) {
    __print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T1, class T2>
void __print(pair<T1, T2> p) {
  cerr << "{ ";
  __print(p.first);
  cerr << " ";
  __print(p.second);
  cerr << " }";
}
template <class T1, class T2>
void __print(unordered_map<T1, T2> mp) {
  cerr << "[ ";
  for (auto i : mp) {
    __print(i);
    cerr << " ";
  }
  cerr << "]";
}
long long binpow(long long a, long long b) {
  a %= MOD;
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % MOD;
    }
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}
void pranav() {
  long long m, n;
  cin >> m >> n;
  long long v[m][n];
  long long ans = -1, shop = -1;
  pair<long long, long long> ind;
  for (long long i = 0; i < m; i++) {
    vector<pair<long long, long long>> v1;
    for (long long j = 0; j < n; j++) {
      cin >> v[i][j];
      v1.push_back({v[i][j], j});
    }
    sort(v1.begin(), v1.end());
    reverse(v1.begin(), v1.end());
    if (ans < min(v1[0].first, v1[1].first)) {
      shop = i;
      ind.first = v1[0].second;
      ind.second = v1[1].second;
      ans = min(v1[0].first, v1[1].first);
    }
  }
  for (long long i = 0; i < n; i++) {
    long long val = -1, flg = 0;
    for (long long j = 0; j < m; j++)
      if (i != shop) val = max(val, v[j][i]), flg = 1;
    if (flg == 1) ans = min(ans, val);
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    pranav();
  }
  return 0;
}
