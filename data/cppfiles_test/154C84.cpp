#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007LL;
const long long mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    int l1, l2, l3;
    scanf("%d%d%d", &l1, &l2, &l3);
    if ((l1 == (l2 + l3)) || ((l2 == l3) && ((l1 % 2) == 0))) {
      puts("YES");
    } else if ((l2 == (l1 + l3)) || ((l1 == l3) && ((l2 % 2) == 0))) {
      puts("YES");
    } else if ((l3 == (l1 + l2)) || ((l1 == l2) && ((l3 % 2) == 0))) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}
