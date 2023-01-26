#include <bits/stdc++.h>
using namespace std;
int ans[1002];
const int N = 1e5 + 10;
int a[N];
int f[1001];
int cnt;
int main() {
  int n;
  cin >> n;
  ans[0] = 1;
  ++cnt;
  memset(f, 0x3f3f3f, sizeof f);
  f[0] = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (ans[a[i]] == 0) ++cnt;
    ans[a[i]] = 1;
    f[a[i]] = min(f[a[i]], a[i]);
    for (int j = 1; j <= 1000; ++j) {
      if (ans[j] == 1 && f[j] < a[i]) {
        if (ans[j ^ a[i]] == 0) cnt++;
        ans[j ^ a[i]] = 1;
        f[j ^ a[i]] = min(a[i], f[j ^ a[i]]);
      }
    }
  }
  printf("%d\n", cnt);
  for (int i = 0; i <= 1000; ++i) {
    if (ans[i]) {
      printf("%d ", i);
    }
  }
}
