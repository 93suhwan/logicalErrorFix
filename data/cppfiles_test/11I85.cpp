#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, f = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar())
    sum = ((sum << 1) + (sum << 3) + (ch ^ 48));
  return f ? -sum : sum;
}
void write(const long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
char getc() {
  char ch = getchar();
  for (; !isalpha(ch); ch = getchar())
    ;
  return ch;
}
long long n, a[550000], tot, kkk, f[550000];
struct nd {
  long long x, y;
} q[550000];
bool cmp(nd a, nd b) {
  if (a.y != b.y) return a.y < b.y;
  return a.x < b.x;
}
int main() {
  n = read();
  for (register long long i = (1); i <= (n); i++) a[i] = read();
  for (register long long i = (1); i <= (n); i++)
    if (a[i] <= i) q[++tot] = (nd){a[i], i - a[i]};
  sort(q + 1, q + tot + 1, cmp);
  for (register long long i = (1); i <= (tot); i++) a[i] = q[i].x;
  f[1] = a[1];
  kkk = 1;
  for (register long long i = (2); i <= (tot); i++) {
    if (a[i] > f[kkk])
      f[++kkk] = a[i];
    else
      f[lower_bound(f + 1, f + kkk + 1, a[i]) - f] = a[i];
  }
  write(kkk), puts("");
}
