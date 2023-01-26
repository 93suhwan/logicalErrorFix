#include <bits/stdc++.h>
using namespace std;
int n, a[200011], b[200011], q[200011][2], l, r;
long long sum[2];
char s[200011];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) b[i] = (s[i] == 'L' ? -1 : 1);
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i) sum[n - i + 1 & 1] += a[i];
  l = 1;
  r = n;
  int cur = n;
  while (l <= r) {
    if (b[cur] == b[cur - 1]) {
      q[cur][0] = a[l];
      q[cur][1] = (r - l + 1 & 1 ? b[cur] : -b[cur]);
      ++l;
    } else {
      swap(sum[1], sum[0]);
      q[cur][0] = a[r];
      q[cur][1] = b[cur];
      --r;
    }
    --cur;
  }
  for (int i = 1; i <= n; ++i)
    if (q[i][1] == -1)
      printf("%d L\n", q[i][0]);
    else
      printf("%d R\n", q[i][0]);
  return 0;
}
