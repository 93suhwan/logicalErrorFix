#include <bits/stdc++.h>
using namespace std;
int T;
int main() {
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    int ls = 0;
    if (n & 1) {
      n--;
      ls += m / 2;
    }
    if (m & 1) m--;
    if (ls > k)
      puts("NO");
    else {
      ls += (n * m) / 2;
      if (ls < k || (ls & 1) != (k & 1))
        puts("NO");
      else
        puts("YES");
    }
  }
  return 0;
}
