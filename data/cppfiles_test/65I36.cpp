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
  int now = cnt + 1;
  cnt = 1;
  int Tmp = 1;
  for (int i = 1; i <= n; ++i) {
    int j = i;
    while (j < n && c[j + 1] == c[i]) ++j;
    int nw = c[i];
    printf("%d %c\n", a[now++], "LR"[c[i]]);
    nw ^= Tmp;
    for (int k = i + 1; k <= j; ++k) {
      printf("%d %c\n", a[cnt++], "LR"[nw]);
      nw ^= 1;
    }
    i = j;
    Tmp ^= 1;
  }
  return 0;
}
