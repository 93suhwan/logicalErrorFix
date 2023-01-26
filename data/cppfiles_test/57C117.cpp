#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 2025;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int t, n;
int a[maxn], pos[maxn];
void reverse(int p) {
  printf("%d ", p);
  for (int i = 1; i <= p / 2; i++) {
    swap(a[i], a[p - i + 1]);
  }
  for (int i = 1; i <= p; i++) {
    pos[a[i]] = i;
  }
}
int main(void) {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int ok = 1;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      if (a[i] % 2 != i % 2) {
        ok = 0;
      }
      pos[a[i]] = i;
    }
    if (!ok) {
      puts("-1");
      continue;
    }
    printf("%d\n", 5 * (n - 1) / 2);
    for (int i = n; i >= 3; i -= 2) {
      reverse(pos[i]);
      reverse(pos[i - 1] - 1);
      reverse(pos[i - 1] + 1);
      reverse(3);
      reverse(i);
    }
    puts("");
  }
  return 0;
}
