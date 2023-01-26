#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
int a[N];
int c[20];
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++) {
      for (int j = 19; j >= 0; j--) {
        if ((a[i] >> j) & 1) c[j]++;
      }
    }
    int x = 0;
    for (int i = 0; i <= 19; i++) x = gcd(x, c[i]);
    if (!x) {
      for (int i = 1; i <= n; i++) printf("%d ", i);
      printf("\n");
      continue;
    }
    vector<int> ans;
    for (int i = 1; i <= x / i; i++) {
      if (x % i == 0) {
        ans.push_back(i);
        if (i * i != x) ans.push_back(x / i);
      }
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) printf("%d ", i);
    printf("\n");
  }
  return 0;
}
