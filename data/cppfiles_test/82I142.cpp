#include <bits/stdc++.h>
using namespace std;
int ar[300005];
char ch[300005];
int n, m, ii, k;
int pre[300005];
vector<pair<int, int>> v;
void solve() {
  scanf("%d%d%s", &n, &m, ch);
  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1];
    if (i & 1) {
      if (ch[i - 1] == '+')
        pre[i]++;
      else
        pre[i]--;
    } else {
      if (ch[i - 1] == '-')
        pre[i]++;
      else
        pre[i]--;
    }
    v.push_back({pre[i] + n, i});
  }
  sort(v.begin(), v.end());
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int len = y - x + 1;
    if (pre[y] - pre[x - 1] == 0) {
      printf("0\n");
      continue;
    }
    if (len & 1)
      printf("1\n");
    else
      printf("2\n%d ", y), y--;
    int val = pre[y] - pre[x - 1];
    if (x % 2 == 0) val *= -1;
    int extra = val - (val / 2);
    if (x % 2 == 0) extra *= -1;
    val = pre[x - 1] + extra + n;
    auto it = lower_bound(v.begin(), v.end(), make_pair(val, x));
    if (it->second < x) it++;
    printf("%d\n", it->second);
  }
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
