#include <bits/stdc++.h>
using namespace std;
template <typename T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
template <typename T>
void read(vector<T>& v, long long n) {
  v.clear();
  v.resize(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
}
template <typename T>
void read(vector<pair<T, T>>& v, long long n) {
  v.clear();
  v.resize(n);
  for (long long i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
}
template <typename T>
void read(vector<vector<T>>& v, long long n, long long m) {
  v.clear();
  v.resize(n, vector<T>(m));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) cin >> v[i][j];
  }
}
template <typename T>
void read(vector<vector<T>>& v, long long n) {
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
}
template <typename T>
void print(vector<T>& v) {
  for (long long i = 0; i < v.size(); i++) cout << v[i] << ' ';
  cout << '\n';
}
template <typename T>
void print(vector<pair<T, T>>& v) {
  for (long long i = 0; i < v.size(); i++)
    cout << v[i].first << ' ' << v[i].second << '\n';
}
template <typename T>
void print(vector<vector<T>>& v) {
  for (long long i = 0; i < v.size(); i++) {
    for (long long j = 0; j < v[i].size(); j++) cout << v[i][j] << ' ';
    cout << '\n';
  }
}
template <typename T>
void print(vector<vector<T>>& v, long long n) {
  for (long long i = 1; i <= n; i++) {
    cout << i << ": ";
    for (long long j = 0; j < v[i].size(); j++) cout << v[i][j] << ' ';
    cout << '\n';
  }
}
template <typename T>
void print(set<T> st) {
  for (auto& it : st) cout << it << ' ';
  cout << '\n';
}
template <typename T>
void print(map<T, T> mp) {
  for (auto& it : mp) cout << it.first << ' ' << it.second << '\n';
  cout << '\n';
}
template <typename T>
void fill(vector<T>& arr, T val) {
  for (long long i = 0; i < (long long)arr.size(); i++) arr[i] = val;
}
template <typename T>
void fill(vector<vector<T>>& arr, T val) {
  for (long long i = 0; i < (long long)arr.size(); i++) {
    for (long long j = 0; j < (long long)arr[i].size(); j++) arr[i][j] = val;
  }
}
long long MAX = 1e17;
long long MIN = -1e17;
long long mod = 1e9 + 7;
long long lim = 1e3 + 5;
long long fastpow(long long a, long long p) {
  long long res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = (a * a) % mod;
      p = p / 2;
    } else {
      res = (res * a) % mod;
      p--;
    }
  }
  return res;
}
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  long long res = ((a + b) % mod + mod) % mod;
  return res;
}
long long mod_sub(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  long long res = ((a - b) % mod + mod) % mod;
  return res;
}
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  long long res = ((a * b) % mod + mod) % mod;
  return res;
}
long long mod_div(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  long long res = (mod_mul(a, fastpow(b, mod - 2)) + mod) % mod;
  return res;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> v;
  read(v, n);
  long long curr = v[n - 1], ret = 0;
  for (long long i = n - 1; i >= 0; i--) {
    if (v[i] > curr) {
      curr = v[i];
      ret++;
    }
  }
  cout << ret << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  bool tt = true;
  if (tt) {
    long long nt;
    cin >> nt;
    for (long long i = 1; i <= nt; i++) solve();
  } else {
    solve();
  }
  return 0;
}
