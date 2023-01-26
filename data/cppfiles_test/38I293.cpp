#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int n, m, q;
vector<int> mp[maxn], t;
char s[maxn];
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
      if (mp[i][j] && mp[i + 1][j - 1]) t.push_back(j - 1);
    }
  }
  sort(t.begin(), t.end());
  int tot = unique(t.begin(), t.end()) - t.begin();
  scanf("%d", &q);
  for (int i = 1, l, r; i <= q; i++) {
    scanf("%d%d", &l, &r);
    int x = lower_bound(t.begin(), t.end(), l) - t.begin();
    if (x == tot || t[x] >= r)
      puts("YES");
    else
      puts("NO");
  }
}
