#include <bits/stdc++.h>
using namespace std;
template <typename Type>
void RIP(Type x) {
  cout << x << "\n";
}
template <typename Type, typename... Targs>
void RIP(Type x, Targs... args) {
  cout << x << " ";
  RIP(args...);
}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N = 1e6 + 10;
const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mo = (1 ? 998244353 : 1000000007);
long long mul(long long a, long long b, long long m = mo) { return a * b % m; }
long long fpow(long long a, long long b, long long m = mo) {
  long long ans = 1;
  for (; b; a = mul(a, a, m), b >>= 1)
    if (b & 1) ans = mul(ans, a, m);
  return ans;
}
inline long long read() {
  long long x = 0, tag = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') tag = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - 48;
  return x * tag;
}
const double pi = acos(-1.0);
double readf() {
  double x;
  if (scanf("%lf", &x) != 1) exit(0);
  return x;
}
template <typename T>
T sqr(T x) {
  return x * x;
}
long long a[N];
void Solve() {
  long long n = read(), m = read();
  cout << m / (n + 1 - (n + 1 >> 1)) << "\n";
}
int main() {
  int T = 1;
  T = read();
  for (int kase = (1); kase <= (T); ++kase) {
    Solve();
  }
  return 0;
}
