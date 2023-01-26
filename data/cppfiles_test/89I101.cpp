#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int t, n, a[maxn];
int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (a[1] % 2 == 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
