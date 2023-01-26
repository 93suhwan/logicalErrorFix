#include <bits/stdc++.h>
using namespace std;
const int N = 5e1 + 9;
const int INF = 0x3f3f3f3f;
long long n;
long long t;
long long a[N];
struct node {
  long long a, b, c;
} ans[N];
long long cnt;
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
    }
    cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
      int ind = i;
      for (int j = i; j <= n; j++) {
        ind = a[ind] > a[j] ? j : ind;
      }
      if (ind == i) {
        continue;
      }
      ans[++cnt].a = i, ans[cnt].b = ind, ans[cnt].c = ind - i;
      long long tmp = a[ind];
      for (int j = ind; j > i; j--) {
        a[j] = a[j - 1];
      }
      a[i] = tmp;
    }
    printf("%lld\n", cnt);
    for (int i = 1; i <= cnt; i++) {
      printf("%lld %lld %lld\n", ans[i].a, ans[i].b, ans[i].c);
    }
  }
  return 0;
}
