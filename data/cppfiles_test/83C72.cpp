#include <bits/stdc++.h>
using namespace std;
int T, n, f[10010], ans, l, r, mid;
string s;
unsigned long long hs[5005][5005];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    cin >> s;
    s.insert(0, " ");
    s += "a";
    for (int i = 1; i <= n; i++) {
      f[i] = n + 1 - i;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) hs[i][j] = hs[i][j - 1] * 133 + (s[j] - '0');
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j < i; j++) {
        if (s[i] > s[j])
          f[i] = max(f[i], f[j] + n + 1 - i);
        else if (s[i] == s[j]) {
          l = 1;
          r = n - i + 1;
          while (l < r) {
            mid = l + r + 1 >> 1;
            if (hs[i][i + mid - 1] == hs[j][j + mid - 1])
              l = mid;
            else
              r = mid - 1;
          }
          if (s[i + l] > s[j + l]) f[i] = max(f[i], f[j] + n + 1 - i - l);
        }
      }
    ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    printf("%d\n", ans);
  }
  return 0;
}
