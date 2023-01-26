#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int a[101000];
int n, flag = 0;
void dfs(int now, int all) {
  if (now == n) {
    if (mp[all] != 0) {
      flag = 1;
    }
    mp[all]++;
    return;
  }
  now++;
  dfs(now, all + a[now]);
  dfs(now, all);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
    }
    mp.clear();
    flag = 0;
    dfs(0, 0);
    if (flag) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}
