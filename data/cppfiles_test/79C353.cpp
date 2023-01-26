#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
const long long MOD = 1e9 + 7;
const long long BASE = 1000;
const long long DIGIT = 4;
const long long LIM = (1 << 24);
const long long INF = (1 << 30);
const long long LIMIT = 1e18;
const long double PI = acos((long double)-1);
const long double EPS = 1e-9;
const int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1};
const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int oo = 1e9;
inline long long gcd(long long a, long long b) {
  long long r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long binPow(long long n, long long k, int p = MOD) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
template <class T>
inline int chkmin(T& a, const T& val) {
  return val < a ? a = val, 1 : 0;
}
template <class T>
inline int chkmax(T& a, const T& val) {
  return a < val ? a = val, 1 : 0;
}
inline unsigned long long isqrt(unsigned long long k) {
  unsigned long long r = sqrt(k) + 1;
  while (r * r > k) r--;
  return r;
}
inline long long icbrt(long long k) {
  long long r = cbrt(k) + 1;
  while (r * r * r > k) r--;
  return r;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
inline int inv(int a, int p = MOD) { return binPow(a, p - 2, p); }
inline int sign(long double x) { return x < -EPS ? -1 : x > +EPS; }
inline int sign(long double x, long double y) { return sign(x - y); }
bool p[10];
int cnt[10];
void Solve() {
  int k;
  string s;
  cin >> k >> s;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < k; ++i) {
    ++cnt[s[i] - '0'];
  }
  for (int i = 1; i < 10; ++i) {
    if (cnt[i] && !p[i]) {
      cout << "1\n" << i << '\n';
      return;
    }
  }
  cout << "2\n";
  if (cnt[2]) {
    int pos = 0;
    for (int i = 0; i < k; ++i) {
      if (s[i] == '2') {
        pos = i + 1;
        break;
      }
    }
    for (int i = pos; i < k; ++i) {
      if (s[i] == '0' || s[i] == '2' || s[i] == '5' || s[i] == '7') {
        cout << 2 << s[i] << '\n';
        return;
      }
    }
  }
  if (cnt[3]) {
    int pos = 0;
    for (int i = 0; i < k; ++i) {
      if (s[i] == '3') {
        pos = i + 1;
        break;
      }
    }
    for (int i = pos; i < k; ++i) {
      if (s[i] == '0' || s[i] == '2' || s[i] == '3' || s[i] == '5') {
        cout << 3 << s[i] << '\n';
        return;
      }
    }
  }
  if (cnt[5]) {
    int pos = 0;
    for (int i = 0; i < k; ++i) {
      if (s[i] == '5') {
        pos = i + 1;
        break;
      }
    }
    for (int i = pos; i < k; ++i) {
      if (s[i] == '0' || s[i] == '2' || s[i] == '7' || s[i] == '5') {
        cout << 5 << s[i] << '\n';
        return;
      }
    }
  }
  if (cnt[7]) {
    int pos = 0;
    for (int i = 0; i < k; ++i) {
      if (s[i] == '7') {
        pos = i + 1;
        break;
      }
    }
    for (int i = pos; i < k; ++i) {
      if (s[i] == '0' || s[i] == '2' || s[i] == '5' || s[i] == '7') {
        cout << 7 << s[i] << '\n';
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int ntest = 1;
  cin >> ntest;
  p[2] = p[3] = p[5] = p[7] = 1;
  while (ntest--) {
    Solve();
  }
}
