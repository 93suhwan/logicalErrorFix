#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, m, k;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n >> m >> k;
    if (m < n - 1 || m > n * (n - 1) / 2) {
      puts("No");
      continue;
    }
    if (n == 1) {
      if (k > 1)
        puts("Yes");
      else
        puts("No");
      continue;
    }
    if (m == n * (n - 1) / 2) {
      if (k > 2)
        puts("Yes");
      else
        puts("No");
      continue;
    }
    if (k > 3)
      puts("Yes");
    else
      puts("No");
  }
}
