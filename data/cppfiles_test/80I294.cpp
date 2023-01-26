#include <bits/stdc++.h>
using namespace std;
long long mod(long long x) {
  return ((x % 1000000007 + 1000000007) % 1000000007);
}
long long add(long long a, long long b) { return mod(mod(a) + mod(b)); }
long long mul(long long a, long long b) { return mod(mod(a) * mod(b)); }
template <class T>
void print(T a) {
  cerr << a;
}
template <class T, class V>
void print(pair<T, V> p);
template <class T>
void print(vector<T> v);
template <class T>
void print(set<T> v);
template <class T, class V>
void print(map<T, V> v);
template <class T>
void print(multiset<T> v);
template <class T, class V>
void print(pair<T, V> p) {
  cerr << "{";
  print(p.first);
  cerr << ",";
  print(p.second);
  cerr << "}";
}
template <class T>
void print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << ",";
  }
  cerr << "]";
}
template <class T>
void print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << ",";
  }
  cerr << "]";
}
template <class T>
void print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    print(i);
    cerr << ",";
  }
  cerr << "]";
}
template <class T, class V>
void print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    print(i);
    cerr << ",";
  }
  cerr << "]";
}
long long modPow(long long a, long long b) {
  if (b == 0) return 1LL;
  if (b == 1) return a % 1000000007;
  long long res = 1;
  while (b) {
    if (b % 2 == 1) res = mul(res, a);
    a = mul(a, a);
    b = b / 2;
  }
  return res;
}
const long long N = 2e5 + 2;
long long fact[N];
void precalc() {
  fact[0] = 1;
  for (long long i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
}
long long inv(long long x) { return modPow(x, 1000000007 - 2); }
long long divide(long long a, long long b) { return mul(a, inv(b)); }
long long nCr(long long n, long long r) {
  return divide(fact[n], mul(fact[r], fact[n - r]));
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 0) {
      if (i < n / 2) {
        cout << i + 1 << " " << n << i + 2 << " " << n << endl;
        return;
      } else {
        cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
        return;
      }
    }
  }
  cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
