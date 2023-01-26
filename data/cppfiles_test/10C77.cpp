#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t, n, k, a[N], ans[N];
int main() {
  cin >> t;
  while (t--) {
    int now = 0;
    map<int, vector<int> > ma;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
      ans[i] = 0;
      scanf("%d", &a[i]);
      ma[a[i]].push_back(i);
    }
    for (auto it_ : ma) {
      vector<int> x = it_.second;
      for (int i = 0; i < x.size() && i < k; i++) ans[x[i]] = ++now;
    }
    now -= now % k;
    for (int i = 1; i <= n; i++) {
      if (ans[i] == 0 || ans[i] > now)
        printf("0 ");
      else
        printf("%d ", ans[i] % k == 0 ? k : ans[i] % k);
    }
    puts("");
  }
  return 0;
}
