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
void _print(T a[], V sz);
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
  cerr << " -> ";
  _print(p.second);
  cerr << "}" << endl;
}
template <class T, class V>
void _print(T a[], V sz) {
  for (V i = 0; i < sz; i++) {
    _print(a[i]);
    cerr << " ";
  }
  cerr << endl;
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]" << endl;
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]" << endl;
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
  cerr << "]" << endl;
}
void _printall(long long t) { cout << t; }
void _printall(int t) { cout << t; }
void _printall(string t) { cout << t; }
void _printall(char t) { cout << t; }
void _printall(long double t) { cout << t; }
void _printall(double t) { cout << t; }
void _printall(unsigned long long t) { cout << t; }
template <class T, class V>
void _printall(T a[], V sz);
template <class T, class V>
void _printall(pair<T, V> p);
template <class T>
void _printall(vector<T> v);
template <class T>
void _printall(set<T> v);
template <class T, class V>
void _printall(map<T, V> v);
template <class T>
void _printall(multiset<T> v);
template <class T, class V>
void _printall(T a[], V sz) {
  for (V i = 0; i < sz; i++) {
    _printall(a[i]);
    cout << " ";
  }
  cout << endl;
}
template <class T, class V>
void _printall(pair<T, V> p) {
  _printall(p.first);
  cout << ",";
  _printall(p.second);
}
template <class T>
void _printall(vector<T> v) {
  for (T i : v) {
    _printall(i);
    cout << " ";
  }
  cout << endl;
}
template <class T>
void _printall(set<T> v) {
  for (T i : v) {
    _printall(i);
    cout << " ";
  }
  cout << endl;
}
template <class T>
void _printall(multiset<T> v) {
  for (T i : v) {
    _printall(i);
    cout << " ";
  }
  cout << endl;
}
template <class T, class V>
void _printall(map<T, V> v) {
  for (auto i : v) {
    _printall(i);
    cout << " ";
  }
  cout << endl;
}
long long INF = 1e18;
long long mod = 1e9 + 7;
long long add(long long a, long long b) {
  return ((a % mod) + (b % mod)) % mod;
}
long long mul(long long a, long long b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long sub(long long a, long long b) {
  return ((a % mod) - (b % mod) + mod) % mod;
}
long long max(long long a, long long b) { return (a > b) ? a : b; }
long long fe(long long base, long long exp) {
  long long ans = 1;
  while (exp) {
    if (exp & 1) ans = mul(ans, base);
    base = mul(base, base);
    exp >>= 1;
  }
  return ans;
}
long long fact(long long n) {
  long long res = 1ll;
  for (long long i = 1ll; i <= n; i++) {
    res = mul(res, i);
  }
  return res;
}
long long modin(long long a) { return fe(a, mod - 2); }
long long nCr(long long a, long long b) {
  if (a < b) return 0;
  return mul(fact(a), mul(modin(fact(b)), modin(fact(a - b))));
}
long long MAXN = 400001;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  vector<pair<char, long long> > v;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string t;
  cin >> t;
  for (int i = 0; i < n; i++) {
    v.push_back({t[i], a[i]});
    if (t[i] == 'R' && a[i] > n) {
      cout << "NO" << endl;
      return;
    }
    if (t[i] == 'B' && a[i] <= 0) {
      cout << "NO" << endl;
      return;
    }
  }
  sort(v.begin(), v.end());
  int index = 1;
  for (int i = 0; i < n; i++) {
    if (v[i].first == 'B') {
      if (index <= v[i].second) {
        index++;
      } else {
        cout << "NO" << endl;
        return;
      }
    } else {
      if (index >= v[i].second) {
        index++;
      } else {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
