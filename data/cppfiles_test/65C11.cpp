#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 1;
int n, a[MAXN];
bool c[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    char c_;
    cin >> c_;
    c[i] = (c_ == 'R');
  }
  int cnt = 0;
  for (int i = 2; i <= n; ++i) cnt += c[i] == c[i - 1];
  sort(a + 1, a + 1 + n);
  int l = cnt, r = cnt + 1;
  int pw;
  for (int i = 1; i <= n; ++i) {
    int j = i;
    while (j < n && c[j + 1] == c[i]) ++j;
    printf("%d %c\n", a[r++], "LR"[c[i]]);
    if (i == 1) pw = c[i];
    for (int k = i + 1; k <= j; ++k) {
      pw ^= 1;
      printf("%d %c\n", a[l--], "LR"[pw]);
    }
    i = j;
  }
  return 0;
}
