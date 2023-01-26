#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, m, q, sum[maxn];
vector<int> mp[maxn];
char s[maxn];
bool flag[maxn];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    mp[i].push_back(0);
    for (int j = 1; j <= m; j++) {
      if (s[j] == '.')
        mp[i].push_back(0);
      else
        mp[i].push_back(1);
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 2; j <= m; j++) {
      if (mp[i][j] && mp[i + 1][j - 1]) flag[j - 1] = 1;
    }
  }
  for (int j = 1; j <= m; j++) sum[j] = sum[j - 1] + flag[j];
  scanf("%d", &q);
  for (int i = 1, l, r; i <= q; i++) {
    scanf("%d%d", &l, &r);
    if (sum[r - 1] - sum[l - 1] != 0)
      puts("NO");
    else
      puts("YES");
  }
}
