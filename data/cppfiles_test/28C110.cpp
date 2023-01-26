#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
long long mod = 1000000007LL;
long long mod2 = 998244353LL;
int t, n, m, h;
long long k;
int q;
int a, b, c;
int main() {
  cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d%d", &a, &b, &c);
    int x = (a % 2);
    int y = (b % 2);
    int z = (c % 2);
    if (x && !y && !z) {
      puts("1");
    } else if (!x && !y && z) {
      puts("1");
    } else if (x && y && !z) {
      puts("1");
    } else if (!x && y && z) {
      puts("1");
    } else {
      puts("0");
    }
  }
  return 0;
}
