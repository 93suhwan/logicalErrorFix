#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, a[N], cnt[N];
long long t[N];
void add(int x, int k) {
  for (; x <= n; x += x & -x) t[x] += k;
}
long long qry(int x) {
  long long s = 0;
  for (; x; x -= x & -x) s += t[x];
  return s;
}
void work() {
  scanf("%d", &n);
  memset(t + 1, 0, n << 3);
  memset(cnt + 1, 0, n << 2);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]), ++cnt[a[i]];
  }
  for (int i = 1; i <= n; ++i) {
    if (cnt[a[i]] >= 2) {
      puts("YES");
      return;
    }
  }
  long long s = 0;
  for (int i = n; i; --i) {
    s += qry(a[i] - 1);
    add(a[i], 1);
  }
  if (s & 1)
    puts("NO");
  else
    puts("YES");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
}
