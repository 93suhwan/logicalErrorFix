#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int temp = ((n * m) / 2) - k;
    if (n % 2) k -= m / 2;
    if (m % 2) temp -= n / 2;
    if (k >= 0 && temp >= 0 && !(k % 2) && !(temp % 2))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
