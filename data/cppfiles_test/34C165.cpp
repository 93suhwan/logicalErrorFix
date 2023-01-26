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
template <class T>
void _print(stack<T> v);
template <class T>
void _print(list<T> v);
template <class T>
void _print(priority_queue<T> v);
template <class T>
void _print(priority_queue<T> v) {
  cerr << "{ ";
  while (!v.empty()) {
    _print(v.top());
    cerr << " ";
    v.pop();
  }
  cerr << " }";
}
template <class T>
void _print(stack<T> v) {
  cerr << "[";
  while (!v.empty()) {
    _print(v.top());
    cerr << " ";
    v.pop();
  }
  cerr << "]";
}
template <class T>
void _print(list<T> v) {
  cerr << "[";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
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
long long power(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res *= a;
    }
    b /= 2;
    a *= a;
  }
  return res;
}
long long mod_pow(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % mod;
    }
    b /= 2;
    a = (a * a) % mod;
  }
  return (res % mod);
}
void usaco(string filename = "") {
  if (((int)(filename).size())) {
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
  }
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n + 1, 0);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  long long ans = -1e18;
  for (int j = n; j >= max(n - 500, 1ll); --j) {
    for (int i = j - 1; i >= max(n - 500, 1ll); --i) {
      long long val = i * 1ll * j;
      val -= k * (a[i] | a[j]);
      ans = max(ans, val);
    }
  }
  cout << ans << "\n";
}
int main() {
  cout << setprecision(15) << fixed;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test = 1, testcase = 1;
  cin >> test;
  while (test--) {
    solve();
  }
}
