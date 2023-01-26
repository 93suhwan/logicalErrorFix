#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int32_t t) { cerr << t; }
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
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long expo(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b = b >> 1;
  }
  return res;
}
long long inv(long long a, long long b) { return expo(a, b - 2, b); }
void swap(long long &x, long long &y) {
  long long temp = x;
  x = y;
  y = temp;
}
long long combination(long long n, long long r, long long m, long long *fact,
                      long long *ifact) {
  long long val1 = fact[n];
  long long val2 = ifact[n - r];
  long long val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
long long fact[1001];
long long invfact[1001];
void factorial_calculation(long long n) {
  fact[0] = 1;
  for (long long i = 1; i <= n; i++) {
    fact[i] = i * fact[i - 1] % 998244353;
  }
  for (long long i = 0; i <= n; i++) {
    invfact[i] = inv(fact[i], 998244353);
  }
}
vector<long long> sieve(long long n) {
  long long *arr = new long long[n + 1]();
  vector<long long> vect;
  for (long long i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
bool ok(long long mid, long long h[], long long n) {
  vector<long long> add(n, 0);
  long long f = 0;
  for (long long i = n - 1; i >= 2; i--) {
    long long x = h[i] + add[i];
    ;
    ;
    ;
    if (x - mid < 0) {
      f = 1;
      break;
    } else {
      long long mn = min((x - mid) / 3, h[i] / 3);
      add[i - 1] += mn;
      add[i - 2] += 2 * mn;
      long long now = x - 3 * mn;
      if (now < mid) {
        break;
      }
    }
  }
  long long now1, now0;
  now1 = h[1] + add[1];
  now0 = h[0] + add[0];
  if (now1 < mid || now0 < mid) {
    f = 1;
  }
  if (f) {
    return false;
  } else
    return true;
}
void solve(long long tc) {
  long long n;
  cin >> n;
  long long h[n];
  for (long long(i) = (0); i < (n); i++) {
    cin >> h[i];
  }
  long long low = 0;
  long long high = 1000000001;
  long long ans = INT_MIN;
  while (low <= high) {
    long long mid = low + (high - low) / 2;
    ;
    bool isok = ok(mid, h, n);
    ;
    if (isok) {
      low = mid + 1;
      ans = max(ans, mid);
    } else {
      high = mid - 1;
    }
  }
  cout << ans << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t = 1;
  cin >> t;
  for (long long tc = 1; tc <= t; tc++) {
    solve(tc);
  }
}
