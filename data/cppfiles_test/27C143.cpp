#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const long long inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
long long tt, test_case;
inline long long rd() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void read(vector<long long> &v) {
  for (auto &x : v) x = rd();
}
void print(vector<long long> &v) {
  for (auto &x : v) cout << x << ' ';
  puts("");
}
template <typename T>
inline void chmx(T &x, T y) {
  if (y > x) x = y;
}
template <typename T>
inline void chmi(T &x, T y) {
  if (y < x) x = y;
}
long long ceil(long long a, long long b) {
  if ((a > 0) ^ (b > 0)) return -1 * (abs(a) / abs(b));
  return (abs(a) + abs(b) - 1) / abs(b);
}
long long floor(long long a, long long b) {
  if ((a > 0) ^ (b > 0)) return -1 * ((abs(a) + abs(b) - 1) / abs(b));
  return (abs(a) / abs(b));
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long mul(long long a, long long b, long long m) {
  long long ret = 0ll;
  while (b) {
    if (b & 1) ret += a, ret %= m;
    a += a, a %= m, b >>= 1;
  }
  return ret;
}
long long mul(long long a, long long b) {
  long long ret = 0ll;
  while (b) {
    if (b & 1) ret += a;
    a += a, b >>= 1;
  }
  return ret;
}
long long ksm(long long a, long long b, long long m) {
  long long ret = 1ll;
  while (b) {
    if (b & 1) ret *= a, ret %= m;
    a *= a, a %= m, b >>= 1;
  }
  return ret;
}
long long ksm(long long a, long long b) {
  long long ret = 1ll;
  while (b) {
    if (b & 1) ret *= a;
    a *= a, b >>= 1;
  }
  return ret;
}
long long inv(long long x, long long m) { return ksm(x, m - 2, m); }
const long long N = 1e5 + 10;
char s[N], t[N];
void run(long long kase) {
  scanf("%s%s", s + 1, t + 1);
  long long n = strlen(s + 1), m = strlen(t + 1);
  if (m > n) {
    puts("NO");
    return;
  }
  long long j = m, flag = 1;
  for (long long i = n; i >= 1; i--) {
    if (s[i] == t[j]) {
      if (flag) {
        if ((n - i) % 2 == 0) j--, flag ^= 1;
      } else {
        if ((n - i) % 2 == 1) j--, flag ^= 1;
      }
    }
    if (j == 0) {
      puts("YES");
      return;
    }
  }
  puts("NO");
}
signed main() {
  tt = rd();
  for (long long test_case = 1; test_case <= tt; test_case++) run(test_case);
  return 0;
}
