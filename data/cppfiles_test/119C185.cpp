#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
template <typename T>
inline void write(T x) {
  int i = 20;
  char buf[21];
  buf[20] = '\n';
  do {
    buf[--i] = x % 10 + '0';
    x /= 10;
  } while (x);
  do {
    putchar(buf[i]);
  } while (buf[i++] != '\n');
}
template <typename T>
inline T readInt() {
  T n = 0, s = 1;
  char p = getchar();
  if (p == '-') s = -1;
  while ((p < '0' || p > '9') && p != EOF && p != '-') p = getchar();
  if (p == '-') s = -1, p = getchar();
  while (p >= '0' && p <= '9') {
    n = (n << 3) + (n << 1) + (p - '0');
    p = getchar();
  }
  return n * s;
}
void i_am_just_a_regular_everyday_normal_MOFO() {
  long long int n, som = 0;
  n = readInt<long long int>();
  vector<int> a(n);
  for (long long int i = 0; i < n; i++) {
    a[i] = readInt<long long int>();
    som += a[i];
  }
  if (som % n == 0)
    cout << "0" << endl;
  else
    cout << "1" << endl;
}
signed main() {
  int t;
  t = readInt<int>();
  while (t--) {
    i_am_just_a_regular_everyday_normal_MOFO();
  }
  return 0;
}
