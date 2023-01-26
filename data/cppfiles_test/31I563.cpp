#include <bits/stdc++.h>
using namespace std;
template <typename T>
void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
namespace FastIO {
const int SIZE = 1 << 16;
char buf[SIZE], str[64];
int l = SIZE, r = SIZE;
int read(char *s) {
  while (r) {
    for (; l < r && buf[l] <= ' '; l++)
      ;
    if (l < r) break;
    l = 0, r = int(fread(buf, 1, SIZE, stdin));
  }
  int cur = 0;
  while (r) {
    for (; l < r && buf[l] > ' '; l++) s[cur++] = buf[l];
    if (l < r) break;
    l = 0, r = int(fread(buf, 1, SIZE, stdin));
  }
  s[cur] = '\0';
  return cur;
}
template <typename type>
bool read(type &x, int len = 0, int cur = 0, bool flag = false) {
  if (!(len = read(str))) return false;
  if (str[cur] == '-') flag = true, cur++;
  for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
  if (flag) x = -x;
  return true;
}
template <typename type>
type read(int len = 0, int cur = 0, bool flag = false, type x = 0) {
  if (!(len = read(str))) return false;
  if (str[cur] == '-') flag = true, cur++;
  for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
  return flag ? -x : x;
}
}  // namespace FastIO
using FastIO::read;
const int N = 1e5 + 10, MAXN = 5e3 + 10;
int a[N];
int main() {
  int t;
  read(t);
  while (t--) {
    int n;
    read(n);
    map<int, int> M;
    for (int i = 1; i <= n; i++) read(a[i]);
    if (n % 2 == 0) {
      for (int i = 1; i <= n; i += 2) {
        printf("%d %d ", -a[i + 1], a[i]);
      }
    } else {
      for (int i = 1; i <= n - 3; i += 2) {
        printf("%d %d ", -a[i + 1], a[i]);
      }
      printf("%d %d %d", a[n], a[n], -(a[n - 2] + a[n - 1]));
    }
    printf("\n");
  }
  return 0;
}
