#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, mod = 998244353, INF = 0x3f3f3f3f;
int T, n;
long long a[N], f[N], sum, x[N];
priority_queue<int> q;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    sum = 0;
    while (!q.empty()) q.pop();
    for (int i = 0; i <= n; i++) f[i] = -1, a[i] = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld", &x[i]);
      a[x[i]]++;
    }
    x[n] = n + 1;
    sort(x, x + n);
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < a[i]; j++) q.push(i);
      if (x[i] > i) {
        f[i] = sum;
        break;
      } else {
        f[i] = sum + a[i];
        sum += i - q.top();
        q.pop();
      }
    }
    for (int i = 0; i <= n; i++) printf("%lld%c", f[i], i == n ? '\n' : ' ');
  }
}
