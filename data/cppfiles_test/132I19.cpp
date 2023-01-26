#include <bits/stdc++.h>
using namespace std;
long long sum;
const int N = 10;
long long a[N];
int t;
bool check(int i, int j, int k) {
  bool flag[5];
  memset(flag, false, sizeof flag);
  for (int q = 1; q <= 7; q++) {
    if (a[i] + a[j] == a[q]) flag[1] = true;
    if (a[j] + a[k] == a[q]) flag[2] = true;
    if (a[k] + a[i] == a[q]) flag[3] = true;
    if (a[i] + a[k] + a[j] == a[q]) flag[4] = true;
  }
  for (int i = 1; i <= 4; i++) {
    if (!flag[i]) return false;
  }
  return true;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    sum = 0;
    for (int i = 1; i <= 7; i++) {
      scanf("%lld", &a[i]);
      sum += a[i];
    }
    for (int i = 1; i <= 7; i++) {
      for (int j = i + 1; j <= 7; j++) {
        for (int k = j + 1; k <= 7; k++) {
          if (a[i] + a[j] + a[k] == sum / 4 && check(i, j, k)) {
            printf("%d %d %d\n", a[i], a[j], a[k]);
            goto done;
          }
        }
      }
    }
  done:
    continue;
  }
  return 0;
}
