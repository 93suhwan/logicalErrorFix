#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, n, m, k;
  cin >> T;
  while (T--) {
    cin >> n >> m >> k;
    if (n % 2 != 0) k -= m / 2;
    if (k % 2 == 0 && k >= 0)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
