#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, m;
    scanf("%d%d%d%d", &a, &b, &c, &m);
    if (m >= max(0, c - 1 - a - b) &&
        m <= max(c - 1, 0) + max(b - 1, 0) + max(c - 1, 0))
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
