#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
int n, m, k;
bool check1() {
  int h = m / 2;
  if (k % h == 0) {
    int t = k / h;
    if ((((n - t) % 2 == 0) && (((n * m) / 2) - k)) || (((n * m) / 2) - k == 0))
      return true;
    else
      return false;
    ;
  } else
    return false;
}
bool check2() {
  int h = n / 2;
  if (((n * m / 2) - k) % h == 0) {
    int t = ((n * m / 2) - k) / h;
    if (((m - t) % 2 == 0 && k) || k == 0)
      return true;
    else
      return false;
  } else
    return false;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &m, &k);
    if ((n % 2) && !(m % 2)) {
      if (check1())
        printf("Yes\n");
      else
        printf("No\n");
    } else if (!(n % 2) && (m % 2)) {
      if (check2())
        printf("Yes\n");
      else
        printf("No\n");
    } else {
      if (k % 2)
        printf("No\n");
      else
        printf("Yes\n");
    }
  }
  return 0;
}
