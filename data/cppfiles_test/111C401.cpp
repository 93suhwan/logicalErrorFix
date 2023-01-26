#include <bits/stdc++.h>
using namespace std;
using ld = long double;
long long mod_add(long long a, long long b, long long m) {
  a %= m;
  b %= m;
  return ((a + b) % m + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a %= m;
  b %= m;
  return ((a * b) % m + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a %= m;
  b %= m;
  return ((a - b) % m + m) % m;
}
void deb(long long x) { cerr << x; }
void deb(string x) { cerr << x; }
void deb(char x) { cerr << x; }
void deb(bool x) { cerr << x; }
void deb(ld x) { cerr << fixed << setprecision(15) << x; }
template <typename T, typename V>
void deb(pair<T, V> P) {
  cerr << "{";
  deb(P.first);
  cerr << ", ";
  deb(P.second);
  cerr << "}";
}
template <typename T, typename V>
void deb(map<T, V> v) {
  cerr << "[ ";
  for (auto &u : v) {
    deb(u);
    cerr << " ";
  }
  cerr << "]";
}
template <typename T>
void deb(vector<T> v) {
  cerr << "[ ";
  for (auto &u : v) {
    deb(u);
    cerr << " ";
  }
  cerr << "]";
}
template <typename T>
void deb(set<T> v) {
  cerr << "[ ";
  for (auto &u : v) {
    deb(u);
    cerr << " ";
  }
  cerr << "]";
}
template <typename T>
void deb(multiset<T> v) {
  cerr << "[ ";
  for (auto &u : v) {
    deb(u);
    cerr << " ";
  }
  cerr << "]";
}
long long highestPowerof2(long long n) {
  long long p = (long long)log2(n);
  return (long long)pow(2, p);
}
void solve() {
  long long n;
  cin >> n;
  string s;
  for (long long i = 0; i < 2 * n; i++) {
    if (i % 2 == 0)
      s.push_back('(');
    else
      s.push_back(')');
  }
  long long k = 0;
  for (long long i = 0; i < n; i++) {
    cout << s << "\n";
    swap(s[k + 1], s[k + 2]);
    k += 2;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t = 1, el = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
