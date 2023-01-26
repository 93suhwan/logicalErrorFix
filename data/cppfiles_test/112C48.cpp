#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double pi = acos(-1.0);
const double inf = 1e100;
template <class T>
inline T read() {
  T x = 0, f = 1;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  };
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + s - 48;
    s = getchar();
  };
  return x * f;
}
template <typename T>
inline void wri(T x) {
  if (x < 0) {
    x = -x;
    putchar('-');
  };
  if (x / 10) wri(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void print(T x, char s) {
  wri(x);
  putchar(s);
}
template <typename T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
int t;
int a[3], m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> a[0] >> a[1] >> a[2] >> m;
    sort(a, a + 3);
    if (m < a[2] - a[0] - a[1] - 1) {
      printf("NO\n");
    } else if (m > a[0] + a[1] + a[2] - 3) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
  return 0;
}
