#include <bits/stdc++.h>
using namespace std;
const int N = 3E5;
const int inf = 1 << 30;
long long read() {
  long long a = 0;
  char b = 1, c;
  do
    if ((c = getchar()) == 45) b = -1;
  while (c < 48 || c > 57);
  do a = (a << 3) + (a << 1) + (c & 15);
  while ((c = getchar()) > 47 && c < 58);
  return a * b;
}
void write(long long x, char c) {
  if (x < 0) putchar(45), x = -x;
  char a[20], s = 0;
  do a[++s] = x % 10 | 48;
  while (x /= 10);
  do putchar(a[s]);
  while (--s);
  putchar(c);
}
int a[N + 1];
long long b[N + 1];
int aska(int x) {
  int res = 0;
  for (; x; x -= x & -x) res += a[x];
  return res;
}
long long askb(int x) {
  long long res = 0;
  for (; x; x -= x & -x) res += b[x];
  return res;
}
int main() {
  int n = read();
  long long ans = 0, s = 0;
  for (int i = 0; i < n; ++i) {
    int x = read();
    ans += s + x * 1LL * i - askb(x);
    for (int j = x; j <= N; j += x) {
      ans -= j * 1LL * (aska(min(j + x - 1, N)) - aska(j - 1));
      for (int k = j; k <= N; k += k & -k) b[k] += x;
    }
    write(ans, ' ');
    for (int j = x; j <= N; j += j & -j) ++a[j];
    s += x;
  }
}
