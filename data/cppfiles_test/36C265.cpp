#include <bits/stdc++.h>
using namespace std;
inline int readint() {
  int a = 0, c = getchar(), f = 1;
  for (; '0' > c || c > '9'; c = getchar())
    if (c == '-') f = -f;
  for (; '0' <= c && c <= '9'; c = getchar())
    a = (a << 3) + (a << 1) + (c ^ 48);
  return a * f;
}
void writeUnsigned(const unsigned &x) {
  if (x > 9) writeUnsigned(x / 10);
  putchar((x - x / 10 * 10) ^ 48);
}
inline void writeint(const int &x) {
  if (x < 0) {
    putchar('-');
    writeUnsigned(-x);
  } else
    writeUnsigned(x);
}
const int MAXN = 105;
const int MAXM = 20005;
bool isPrime[MAXM];
int a[MAXN];
int main() {
  memset(isPrime + 2, true, MAXM - 2);
  for (int i = (2); i <= (MAXM - 1); ++i)
    if (isPrime[i])
      for (int j = i << 1; j < MAXM; j += i) isPrime[j] = false;
  for (int T = readint(); T; --T) {
    int n = readint(), sum = 0;
    for (int i = (1); i <= (n); ++i) sum += (a[i] = readint());
    if (!isPrime[sum]) {
      printf("%d\n", n);
      for (int i = (1); i <= (n); ++i) printf("%d ", i);
    } else
      for (int i = (1); i <= (n); ++i)
        if (!isPrime[sum - a[i]]) {
          printf("%d\n", n - 1);
          for (int j = (1); j <= (n); ++j)
            if (i != j) printf("%d ", j);
          break;
        }
    putchar('\n');
  }
  return 0;
}
