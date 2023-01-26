#include <bits/stdc++.h>
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
inline int MAX(int x, int y) { return x > y ? x : y; }
inline int MIN(int x, int y) { return x < y ? x : y; }
using namespace std;
template <typename T>
T gcd(T a, T b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
inline char nc() {
  static char buf[1000000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
template <typename T>
inline void read(T& sum) {
  char ch = getchar();
  T tf = 0;
  sum = 0;
  while ((ch < '0' || ch > '9') && (ch != '-')) ch = getchar();
  tf = ((ch == '-') && (ch = getchar()));
  while (ch >= '0' && ch <= '9') sum = sum * 10 + (ch - 48), ch = getchar();
  (tf) && (sum = -sum);
}
template <typename T>
inline void write(T x) {
  char F[200];
  T tmp = x > 0 ? x : -x;
  if (x < 0) putchar('-');
  T cnt = 0;
  while (tmp > 0) {
    F[cnt++] = tmp % 10 + '0';
    tmp /= 10;
  }
  while (cnt > 0) putchar(F[--cnt]);
}
void seino();
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) seino();
  return 0;
}
void seino() {
  long long a, b, c;
  cin >> a >> b >> c;
  if (a == b || c == a || c == b)
    cout << "-1\n";
  else {
    long long s = (MAX(a, b) - MIN(a, b));
    if (s * 2 < a || s * 2 < b || s * 2 < c)
      cout << "-1\n";
    else {
      long long ans = (s + c) % (s * 2);
      if (ans == 0) ans = (s * 2);
      cout << ans << "\n";
    }
  }
}
