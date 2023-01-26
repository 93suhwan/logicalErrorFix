#include <bits/stdc++.h>
using namespace std;
int T, n;
vector<int> s[1010];
void clr() {
  for (int i = 1; i <= n; i++) s[i].clear();
}
int main() {
  int l, r, lst;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    clr();
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &l, &r);
      s[l].push_back(r);
    }
    for (int i = 1; i <= n; i++)
      if (!s[i].empty()) sort(s[i].begin(), s[i].end());
    for (int i = 1; i <= n; i++) {
      lst = i;
      for (int j = 0; j < s[i].size(); j++) {
        printf("%d %d %d\n", i, s[i][j], lst);
        lst = s[i][j] + 1;
      }
    }
  }
  return 0;
}
