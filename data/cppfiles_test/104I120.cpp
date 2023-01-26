#include <bits/stdc++.h>
using namespace std;
long long T, n, m, cnt, num[200100], ri[200100];
vector<long long> ans;
inline void work(long long u) {
  num[u] = num[u + 1] = num[u + 2] = (num[u] ^ num[u + 1] ^ num[u + 2]);
  ans.push_back(u);
}
inline void work(long long u, long long v) {
  long long i, j, k;
  i = u, j = v - 1;
  if ((j - i) & 1) {
    for (k = i; k < j; k += 2) work(k);
    for (k = j - 1; k > i; k -= 2) work(k - 2);
  } else {
    for (k = i; k < j; k += 2) work(k);
  }
}
int main() {
  long long i, j, p, q, t;
  cin >> T;
  while (T--) {
    cnt = 0;
    ans.clear();
    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
      scanf("%lld", &num[i]);
      cnt += num[i];
    }
    if ((cnt & 1) || cnt == n) {
      puts("NO");
      continue;
    }
    ri[n + 1] = 0;
    for (i = n; i >= 1; i--) {
      if (!num[i])
        ri[i] = 0;
      else
        ri[i] = ri[i + 1] + 1;
    }
    for (p = 1; p < n; p++) {
      if (num[p] && !num[p + 1]) {
        for (q = p + 1; q < n; q++)
          if (!num[q] && num[q + 1]) break;
        if (q < n)
          work(p, q + 1);
        else
          break;
      }
    }
    for (i = 1; i <= n - 2; i++)
      if (!num[i] && num[i + 1] && num[i + 2]) work(i);
    for (i = n - 2; i >= 1; i--)
      if (!num[i + 2] && num[i + 1] && num[i]) work(i);
    for (i = 1; i <= n; i++)
      if (num[i]) break;
    if (i <= n) {
      puts("NO");
      continue;
    }
    puts("YES");
    printf("%lld\n", (long long)ans.size());
    for (i = 0; i < ans.size(); i++) printf("%lld ", ans[i]);
    puts("");
  }
}
