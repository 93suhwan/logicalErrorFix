#include <bits/stdc++.h>
using namespace std;
template <class T, class... U>
void re(T &&a, U &&...b) {
  cin >> forward<T>(a);
  (long long int[]){(cin >> forward<U>(b), 0)...};
}
template <class T, class... U>
void pr(T &&a, U &&...b) {
  cout << forward<T>(a);
  (long long int[]){(cout << " " << forward<U>(b), 0)...};
  cout << " ";
}
void _print(long long int t) { cerr << t; }
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
template <class T>
void print(const T *const arr, long long int count) {
  for (long long int i = 0; i < count; ++i) {
    _print(arr[i]);
    cerr << " ";
  }
  cerr << '\n';
}
long long int gcd(long long int a, long long int b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long int expo(long long int a, long long int b, long long int mod) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}
void extendgcd(long long int a, long long int b, long long int *v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  long long int x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
}
void swap(long long int &x, long long int &y) {
  long long int temp = x;
  x = y;
  y = temp;
}
long long int mod_add(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long int mod_mul(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long int mod_sub(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long int inverse(long long int a, long long int p) {
  return expo(a, p - 2, p);
}
long long int mod_div(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, inverse(b, m), m) + m) % m;
}
long long int fact[200001];
void f() {
  fact[0] = 1, fact[1] = 1;
  for (long long int i = 2; i < 200001; i++) {
    fact[i] = mod_mul(i, fact[i - 1], 998244353);
  }
}
long long int ncr(long long int n, long long int r, long long int mod) {
  if (r == 0) return 1;
  return (fact[n] * inverse(fact[r], mod) % mod * inverse(fact[n - r], mod) %
          mod) %
         mod;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T = 1;
  cin >> T;
  f();
  for (long long int i = 1; i < T + 1; i++) {
    long long int n;
    re(n);
    long long int a[n], b[n];
    map<long long int, long long int> m;
    for (long long int i = 0; i < n; i++) {
      re(a[i]);
      b[i] = a[i];
      m[a[i]]++;
    }
    sort(b, b + n);
    long long int mx = b[n - 1], mx1 = -1;
    for (long long int i = n - 1; i >= 0; i--) {
      if (b[i] != mx) {
        mx1 = b[i];
        break;
      }
    }
    long long int ans = fact[n];
    long long int k = m[mx1];
    long long int x = n - 1 - k;
    long long int z = 0;
    if (mx1 != -1 && mx - mx1 > 1) {
      cout << 0;
      goto label;
    }
    if (m[mx] > 1) {
      pr(fact[n] % 998244353);
      goto label;
    }
    for (long long int i = 0; i < x + 1; i++) {
      long long int y =
          ((ncr(x, i, 998244353) % 998244353) * (fact[n - i - 1] % 998244353)) %
          998244353;
      y = (y * fact[i]) % 998244353;
      z += y;
      z %= 998244353;
    }
    if (n >= 13) ans += 998244353;
    pr(mod_sub(ans, z, 998244353));
  label:;
    cout << '\n';
    if (i == 15) {
      cout << n << '\n';
      for (long long int i = 0; i < n; i++) pr(a[i]);
    }
    cout << '\n';
  }
  return 0;
}
