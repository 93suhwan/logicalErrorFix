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
const int N = 2e5 + 10;
long long x[N], y[N], ansx[N], ansy[N];
int pos[N];
int main() {
  int t;
  read(t);
  while (t--) {
    long long n, m;
    read(n), read(m);
    long long sumx = 0, sumy = 0;
    for (int i = 1; i <= n; i++) {
      read(x[i]), read(y[i]);
      sumx += x[i], sumy += y[i];
      ansx[i] = ansy[i] = 0;
      if (x[i] <= y[i]) {
        if (2 * x[i] < m) {
          sumy -= m - 2 * x[i];
          y[i] -= m - 2 * x[i];
          ansy[i] += m - 2 * x[i];
        }
      } else {
        if (2 * y[i] < m) {
          sumx -= m - 2 * y[i];
          x[i] -= m - 2 * y[i];
          ansx[i] += m - 2 * y[i];
        }
      }
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) {
      long long cal = min(m, 2 * min(x[i], y[i]));
      if (sumx > sumy) {
        long long Min = min(cal, min(sumx - sumy, x[i]));
        x[i] -= Min;
        sumx -= Min;
        ansx[i] += Min;
        cal -= Min;
        if (cal == 0) continue;
        int tem = (min(x[i], y[i]), cal / 2);
        cal -= tem * 2, x[i] -= tem, y[i] -= tem;
        ansx[i] += tem, ansy[i] += tem;
        if (x[i] == 0) {
          ansy[i] += cal;
          sumy -= cal;
        } else if (y[i] == 0) {
          ansx[i] += cal;
          sumx -= cal;
        } else if (cal) {
          pos[++tot] = i;
        }
      } else {
        long long Min = min(cal, min(sumy - sumx, y[i]));
        y[i] -= Min;
        sumy -= Min;
        ansy[i] += Min;
        cal -= Min;
        if (cal == 0) continue;
        int tem = (min(x[i], y[i]), cal / 2);
        cal -= tem * 2, y[i] -= tem, x[i] -= tem;
        ansx[i] += tem, ansy[i] += tem;
        if (x[i] == 0) {
          ansy[i] += cal;
          sumy -= cal;
        } else if (y[i] == 0) {
          ansx[i] += cal;
          sumx -= cal;
        } else if (cal) {
          pos[++tot] = i;
        }
      }
    }
    int flag = 0;
    if (sumx > sumy) flag = 1;
    for (int i = 1; i <= tot; i++) {
      if (i % 2 == flag)
        sumx -= 1, ansx[i] += 1;
      else
        sumy -= 1, ansy[i] += 1;
    }
    printf("%lld\n", abs(sumx - sumy));
    for (int i = 1; i <= n; i++) {
      printf("%lld %lld\n", ansx[i], ansy[i]);
    }
  }
  return 0;
}
