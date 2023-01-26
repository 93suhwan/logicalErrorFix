#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int A[maxn];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    int sum = 0;
    int a = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &A[i]);
      sum += A[i];
      a = max(a, A[i]);
    }
    printf("%lf\n", (double)(sum - a) / (n - 1) + a);
  }
  return 0;
}
