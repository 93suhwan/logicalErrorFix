#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int T, n;
int a[maxn], po[maxn], sum[35];
int main() {
  po[0] = 1;
  for (int i = 1; i <= 30; i++) po[i] = po[i - 1] << 1;
  scanf("%d", &T);
  while (T--) {
    memset(sum, 0, sizeof(sum));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= 30; j++)
        if (a[i] & po[j]) sum[j]++;
    for (int k = 1; k <= n; k++) {
      bool flag = true;
      for (int i = 0; i <= 30; i++)
        if (sum[i] % k) flag = false;
      if (flag) cout << k << " ";
    }
    cout << endl;
  }
  return 0;
}
