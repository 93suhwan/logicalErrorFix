#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, w = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    w |= ch == '-';
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return w ? -x : x;
}
inline long long readll() {
  long long x = 0, w = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    w |= ch == '-';
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return w ? -x : x;
}
int Tc;
int n, a[200005], flag;
int ans[200005], cnt;
void work(int x) {
  ans[++cnt] = x;
  int tmp = a[x] ^ a[x + 1] ^ a[x + 2];
  a[x] = a[x + 1] = a[x + 2] = tmp;
}
void solve() {
  cnt = 0;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    sum += a[i];
  }
  if (sum & 1) {
    printf("NO\n");
    return;
  }
  sum = 0, flag = 0;
  for (int i = 1; i <= n; i++) {
    sum ^= a[i];
    if (sum == 0 && a[i] == 0) flag = i;
  }
  if (!flag) {
    printf("NO\n");
    return;
  }
  for (int i = flag - 1; i >= 1; i--) {
    if (!a[i]) continue;
    if (a[i - 1])
      work(i - 1);
    else {
      work(i - 2);
      if (a[i] == 1) work(i - 1);
    }
  }
  for (int i = flag + 1; i <= n; i++) {
    if (!a[i]) continue;
    if (a[i + 1])
      work(i - 1);
    else {
      work(i);
      if (a[i] == 1) work(i - 1);
    }
  }
  printf("YES\n%d", cnt);
  for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
  printf("\n");
}
int main() {
  Tc = read();
  while (Tc--) solve();
  return 0;
}
