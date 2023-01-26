#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long pos = 1, num = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') pos = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    num = num * 10 + (long long)(ch - '0');
    ch = getchar();
  }
  return pos * num;
}
void write(long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writesp(long long x) {
  write(x);
  putchar(' ');
}
void writeln(long long x) {
  write(x);
  putchar('\n');
}
const long long N = 1e5 + 10;
long long T, n, a[N], t[N], ans, res, m;
struct node {
  long long id, val;
} b[N];
bool cmp1(node x, node y) {
  return x.val == y.val ? x.id > y.id : x.val > y.val;
}
bool cmp2(node x, node y) { return x.id < y.id; }
void merge(long long l, long long r) {
  if (l == r) return;
  long long mid = (l + r) / 2, i = l, j = mid + 1, k = l;
  merge(l, mid);
  merge(mid + 1, r);
  while (i <= mid && j <= r) {
    if (a[i] >= a[j])
      t[k] = a[i++];
    else
      t[k] = a[j++], res += mid - i + 1;
    k++;
  }
  while (i <= mid) t[k++] = a[i++];
  while (j <= r) t[k++] = a[j++];
  for (i = l; i <= r; i++) a[i] = t[i];
}
signed main() {
  T = read();
  while (T--) {
    n = read();
    m = read();
    for (long long i = 1; i <= n * m; i++) b[i].id = i, b[i].val = read();
    sort(b + 1, b + n * m + 1, cmp1);
    for (long long i = 1; i <= n; i++)
      sort(b + (i - 1) * m + 1, b + (i - 1) * m + m + 1, cmp2);
    for (long long i = 1; i <= n * m; i++) a[i] = b[i].val;
    ans = 0;
    for (long long i = 1; i <= n; i++) {
      res = 0;
      merge((i - 1) * m + 1, (i - 1) * m + m);
      ans += res;
    }
    writeln(ans);
  }
}
