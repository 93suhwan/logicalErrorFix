#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 3e5 + 10;
inline int getnum(char c) { return (c == '+') ? 1 : -1; }
int sum[maxn * 2];
char str[maxn * 2];
vector<int> v[maxn * 4 + 10];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", str);
    sum[0] = 0;
    int flag = 1;
    for (int i = 1; i <= n; i++) {
      int id = i - 1;
      sum[i] = sum[i - 1] + getnum(str[id]) * flag;
      v[sum[i] + sum[i - 1] + maxn * 2].push_back(i);
      flag = -flag;
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      if ((sum[r] - sum[l - 1]) == 0) {
        printf("0\n");
        continue;
      }
      if ((r - l + 1) & 1) {
        printf("1\n");
        int x = sum[r] + sum[l - 1] + maxn * 2;
        int ans = v[x][lower_bound(v[x].begin(), v[x].end(), l) - v[x].begin()];
        printf("%d\n", ans);
      } else {
        printf("2\n");
        int ans1, ans2 = r;
        r = r - 1;
        int x = sum[r] + sum[l - 1] + maxn * 2;
        ans1 = v[x][lower_bound(v[x].begin(), v[x].end(), l) - v[x].begin()];
        printf("%d %d\n", ans1, ans2);
      }
    }
    for (int i = 1; i <= n; i++) {
      v[sum[i] + sum[i - 1] + maxn * 2].clear();
    }
  }
  return 0;
}
