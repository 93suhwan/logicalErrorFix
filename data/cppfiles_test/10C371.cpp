#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int M = 2e2 + 7;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
pair<int, int> a[N];
int cnt[N];
int num[N];
int ans[N];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    memset(cnt, 0, sizeof cnt);
    memset(num, 0, sizeof num);
    memset(ans, 0, sizeof ans);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i].first);
      cnt[a[i].first]++;
      a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    stack<int> pos;
    for (int i = 1; i <= n; i++) {
      if (cnt[a[i].first] >= k) {
        for (int j = 1; j <= k; j++) ans[a[i + j - 1].second] = j;
        i = i + cnt[a[i].first] - 1;
      } else
        pos.push(a[i].second);
    }
    int t = pos.size() / k;
    for (int i = 0; i <= t - 1; i++) {
      for (int j = 1; j <= k; j++) {
        ans[pos.top()] = j;
        pos.pop();
      }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}
