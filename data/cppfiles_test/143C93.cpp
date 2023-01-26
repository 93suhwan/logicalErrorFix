#include <bits/stdc++.h>
using namespace std;
long long a[1000005], f[1000005];
struct node {
  long long w;
  bool operator<(const node &A) const { return w < A.w; }
};
priority_queue<node> q;
int main() {
  long long tt;
  scanf("%lld", &tt);
  while (tt--) {
    long long n;
    scanf("%lld", &n);
    for (long long i = 0; i <= n; i++) f[i] = 0;
    for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]), f[a[i]]++;
    while (!q.empty()) q.pop();
    long long add = 0, flag = 1;
    for (long long i = 0; i <= n; i++) {
      if (flag)
        printf("%lld ", add + f[i]);
      else
        printf("-1 ");
      if (!f[i] && q.empty())
        flag = 0;
      else if (!f[i]) {
        add += i - q.top().w;
        q.pop();
      } else {
        for (long long j = 2; j <= f[i]; j++) q.push((node){i});
      }
    }
    printf("\n");
  }
  return 0;
}
