#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int P = 1000000007;
const int V = 1010;
int a[V];
long long s[V][V], L[V][V];
int n;
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) {
      if (i % 2 == 1)
        s[i][i] = a[i], L[i][i] = 0;
      else
        s[i][i] = -a[i], L[i][i] = -a[i];
      for (int j = i + 1; j <= n; ++j) {
        if (j % 2 == 1)
          s[i][j] = s[i][j - 1] + a[j];
        else
          s[i][j] = s[i][j - 1] - a[j];
        L[i][j] = min(L[i][j - 1], s[i][j]);
      }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i += 2) {
      for (int j = i + 1; j <= n; j += 2) {
        if (j == i + 1) {
          ans += min(a[i], a[j]);
          continue;
        }
        long long M = L[i + 1][j - 1];
        long long wi = a[i];
        long long wj = a[j];
        if (s[i + 1][j - 1] < 0)
          wi += s[i + 1][j - 1], M -= s[i + 1][j - 1];
        else if (s[i + 1][j - 1] > 0)
          wj -= s[i + 1][j - 1];
        wi = min(wi, wi + M + 1);
        wj = min(wj, wj + M + 1);
        long long D = min(wi, wj);
        if (D < 0) continue;
        ans += D;
      }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
