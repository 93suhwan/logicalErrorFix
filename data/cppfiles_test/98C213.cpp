#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 10;
int pos[MAXN];
char s[MAXN], t[MAXN];
void solve() {
  scanf("%s %s", s, t);
  for (int i = (0), iend = (26); i < iend; ++i) pos[s[i] - 'a'] = i;
  int ans = 0;
  for (int i = (1), iend = (strlen(t)); i < iend; ++i)
    ans += abs(pos[t[i] - 'a'] - pos[t[i - 1] - 'a']);
  printf("%d\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
