#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
double a[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int q;
    cin >> q;
    double sum = 0;
    double max = -1e9 - 1;
    for (int i = 0; i < q; i++) {
      scanf("%lf", &a[i]);
      sum += a[i];
      if (a[i] > max) max = a[i];
    }
    double ans = sum - max;
    double res = ans / (q - 1) + max;
    printf("%.9lf\n", res);
  }
  return 0;
}
