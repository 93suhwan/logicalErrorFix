#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int t, n;
long long a[maxn];
int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    long long tt = 2;
    int flag = 0, ff = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] % tt == 0) {
        flag = 1;
        break;
      }
      tt *= (i + 2);
      if (tt > 1000000000) {
        ff = 1;
        break;
      }
    }
    if (!flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
