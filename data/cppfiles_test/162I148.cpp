#include <bits/stdc++.h>
using namespace std;
long long M[200010], n, Rem[200010];
long long find_ans(long long l, long long r) {
  if (l == r) return r;
  long long mid = (l + r) / 2, Mark = 0;
  for (int i = 0; i <= n + 1; i++) Rem[i] = M[i];
  for (long long i = 2; i <= n + 1; i++) {
    long long Max = max((mid - Rem[i - 2] + 1) / 2, (Rem[i] - mid) / 3);
    long long ling = 0;
    Max = max(ling, Max);
    Rem[i] -= (Max * 3);
    Rem[i - 1] += Max;
    if (Rem[i] < 0) {
      Mark = 1;
      break;
    }
  }
  if (Mark == 0)
    return find_ans(mid + 1, r);
  else
    return find_ans(l, mid);
}
int main(void) {
  long long t, add;
  scanf("%lld", &t);
  while (t--) {
    add = 0;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
      scanf("%lld", &M[i]);
      add += M[i];
    }
    M[n] = 0;
    M[n + 1] = 0;
    long long mid = find_ans(1, add / n);
    int Mark = 0;
    for (int i = 0; i <= n + 1; i++) Rem[i] = M[i];
    for (long long i = 2; i <= n + 1; i++) {
      long long Max = max((mid - Rem[i - 2] + 1) / 2, (Rem[i] - mid) / 3);
      long long ling = 0;
      Max = max(ling, Max);
      Rem[i] -= (Max * 3);
      Rem[i - 1] += Max;
      if (Rem[i] < 0) {
        Mark = 1;
        break;
      }
    }
    if (Mark == 0)
      printf("%lld\n", mid);
    else
      printf("%lld\n", mid - 1);
  }
}
