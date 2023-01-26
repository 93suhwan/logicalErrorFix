#include <bits/stdc++.h>
using namespace std;
int n;
int c[1005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i]);
    if (i & 1)
      c[i] += c[i - 1];
    else
      c[i] = c[i - 1] - c[i];
  }
  int ans = 0;
  int now, tmp;
  for (int i = 1; i <= n; i += 2) {
    now = c[i];
    for (int j = i + 1; j <= n; j += 2) {
      tmp = now - max(c[i - 1], c[j]);
      if (tmp > 0) ans += tmp;
      now = min(now, c[j] + 1);
    }
  }
  cout << ans;
  return 0;
}
