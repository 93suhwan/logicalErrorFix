#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
int n, m, k, shuzhi;
bool check1() {
  int h = m / 2;
  int l = n / 1;
  if (k <= h * l) {
    int temp = k / n;
    int t = k % n;
    if (t != 0) {
      int shengxia = n - t;
      if (shengxia % 2 != 0)
        return false;
      else {
        shuzhi -= shengxia / 2 * 2;
        m -= (temp + 1) * 2;
        if (n % 2 == 0 && m * (n / 2) == shuzhi)
          return true;
        else
          return false;
      }
    } else {
      m -= (temp)*2;
      if ((shuzhi != 0 && n % 2 == 0 && m * (n / 2) == shuzhi) || shuzhi == 0) {
        return true;
      } else
        return false;
    }
  }
  return false;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &m, &k);
    shuzhi = ((n * m) / 2) - k;
    if (check1())
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
