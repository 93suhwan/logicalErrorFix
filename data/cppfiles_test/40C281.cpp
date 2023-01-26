#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int sum1[N], sum2[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int m;
    scanf("%d", &m);
    memset(sum1, 0, sizeof(sum1));
    memset(sum2, 0, sizeof(sum2));
    for (int i = 1; i <= m; i++) {
      scanf("%d", &sum1[i]);
      sum1[i] += sum1[i - 1];
    }
    for (int i = 1; i <= m; i++) {
      scanf("%d", &sum2[i]);
      sum2[i] += sum2[i - 1];
    }
    long long minn = 1e10;
    for (int i = 1; i <= m; i++) {
      long long maxx = 0;
      maxx = max(sum2[i - 1], sum1[m] - sum1[i]);
      minn = min(minn, maxx);
    }
    printf("%lld\n", minn);
  }
  return 0;
}
