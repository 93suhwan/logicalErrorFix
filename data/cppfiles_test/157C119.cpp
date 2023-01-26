#include <bits/stdc++.h>
using namespace std;
void read() { return; }
void wrt() { cout << (string) "\n"; }
void wrt(long long t) { cout << t; }
void wrt(int t) { cout << t; }
void wrt(char t) { cout << t; }
void wrt(string t) { cout << t; }
void wrt(double t) { cout << t; }
template <class T>
void wrt(set<T> v);
template <class T>
void wrt(vector<T> v);
template <class T>
void wrt(multiset<T> v);
template <class T, class V>
void wrt(map<T, V> v);
template <class T, class V>
void wrt(pair<T, V> p);
template <size_t T>
void wrt(const char (&a)[T]) {
  string s = a;
  wrt(s);
  wrt();
}
template <class T>
void wrt(set<T> v) {
  for (T i : v) {
    wrt(i);
    wrt(' ');
  }
  wrt();
}
template <class T>
void wrt(vector<T> v) {
  for (T i : v) {
    wrt(i);
    wrt(' ');
  }
  wrt();
}
template <class T>
void wrt(multiset<T> v) {
  for (T i : v) {
    wrt(i);
    wrt(' ');
  }
  wrt();
}
template <class T, class V>
void wrt(map<T, V> v) {
  for (auto i : v) {
    wrt(i);
    wrt(' ');
  }
  wrt();
}
template <class T, class V>
void wrt(pair<T, V> p) {
  wrt(p.first);
  wrt(' ');
  wrt(p.second);
  wrt();
}
template <class T, class... V>
void wrt(T x, V... args) {
  (wrt(x), wrt(' '), wrt(args...));
}
template <class T, class... V>
void read(T &x, V &...args) {
  ((cin >> x), read(args...));
}
template <class T>
void readArr(T &arr, int x, int y) {
  for (int i = (int)x; i < (int)y; ++i) cin >> arr[i];
}
template <class T>
void wrtArr(T &arr, int x, int y) {
  for (int i = (int)x; i < (int)y; ++i) cout << arr[i] << ' ';
  wrt();
}
const int N = 5005;
const int INF = 2e9;
const int MOD = 998244353;
const double PI = 3.14159265358979312;
const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
template <class T>
long long _sum(vector<T> &arr) {
  return accumulate(arr.begin(), arr.end(), 0ll);
}
template <class T>
bool _min(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool _max(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
long long _bits(long long x) {
  long long cnt = 0;
  while (x > 0) {
    cnt++;
    x >>= 1;
  }
  return cnt;
}
long long _setbits(long long x) {
  long long cnt = 0;
  while (x > 0) {
    if (x & 1) cnt++;
    x >>= 1;
  }
  return cnt;
}
long long _gcd(long long a, long long b) {
  return (b == 0) ? (a) : (_gcd(b, a %= b));
}
long long _lcm(long long a, long long b) {
  if (a < b) swap(a, b);
  return a / _gcd(a, b) * b;
}
long long _add(long long x, long long y) {
  x %= MOD, y %= MOD;
  return (x + y) % MOD;
}
long long _sub(long long x, long long y) {
  x %= MOD, y %= MOD;
  return (x - y + MOD) % MOD;
}
long long _mul(long long x, long long y) {
  x %= MOD, y %= MOD;
  return (x * 1ll * y) % MOD;
}
long long _pow(long long x, long long y) {
  if (y == 0)
    return 1;
  else if (y % 2 == 0) {
    long long _tmp = _pow(x, y / 2);
    return _mul(_tmp, _tmp);
  } else
    return _mul(x, _pow(x, y - 1));
}
long long _inv(long long p) { return _pow(p, MOD - 2); }
long long _div(long long x, long long y) {
  x %= MOD, y %= MOD;
  return _mul(x, _inv(y));
}
long long _nCr(long long n, long long r, vector<long long> &fact) {
  return _mul(fact[n], _inv(_mul(fact[r], fact[n - r])));
}
struct combi {
  int n;
  vector<long long> facts, finvs, invs;
  combi(int _n) : n(_n), facts(_n), finvs(_n), invs(_n) {
    facts[0] = facts[1] = 1;
    finvs[0] = finvs[1] = 1;
    invs[0] = invs[1] = 1;
    for (int i = 2; i < n; i++) {
      facts[i] = (facts[i - 1] * i) % MOD;
      invs[i] = (invs[MOD % i] * (MOD - MOD / i)) % MOD;
      finvs[i] = (finvs[i - 1] * invs[i]) % MOD;
    }
  }
  inline long long fact(int n) { return facts[n]; }
  inline long long finv(int n) { return finvs[n]; }
  inline long long inv(int n) { return invs[n]; }
  inline long long ncr(int n, int k) {
    return n < k or k < 0 ? 0
                          : facts[n] * (finvs[k] * finvs[n - k] % MOD) % MOD;
  }
};
combi C(N);
void solveTestCase(int test_case) {
  int n, k;
  read(n, k);
  string s;
  read(s);
  if (k == 0 || count(s.begin(), s.end(), '1') < k) return wrt(1);
  int a = 0, b = -1, c = 0;
  long long ans = 0;
  int cnt = 0;
  while (1) {
    while (c < n && cnt <= k) {
      if (s[c] == '1' && cnt == k) break;
      if (s[c] == '1') cnt++;
      c++;
    };
    ans = _add(ans, C.ncr(c - a, k));
    if (a) ans = _sub(ans, C.ncr(b - a + 1, k - 1));
    b = c - 1;
    while (a < c && cnt == k) {
      if (s[a] == '1') cnt--;
      a++;
    }
    if (c == n) break;
  }
  wrt(ans);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  ;
  int test_cases = 1;
  for (int t = 1; t <= test_cases; t++) solveTestCase(t);
  return 0;
}
