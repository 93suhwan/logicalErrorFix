#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &n, &m, &k);
    if (n % 2 == 0 && m % 2 == 0) {
      puts(k % 2 == 0 ? "YES" : "NO");
    } else if (n % 2) {
      puts(k >= m / 2 && (k - m / 2) % 2 == 0 ? "YES" : "NO");
    } else {
      puts(k > n * (m - 1) / 2 || k % 2 ? "NO" : "YES");
    }
  }
  return 0;
}
