#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, cnt, a[N], s[N], ans[N], op[N];
char ch[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  scanf("%s", ch + 1);
  for (int i = 1; i <= n; i++) s[i] = (ch[i] == 'R');
  for (int i = 1; i < n; i++) cnt += (s[i] != s[i + 1]);
  int l = n - cnt, r = n - cnt;
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      ans[i] = n - cnt;
      op[ans[i]] = s[i];
    } else {
      if (s[i] == s[i - 1]) {
        ans[i] = --l;
        op[ans[i]] = op[l + 1] ^ 1;
      } else {
        ans[i] = ++r;
        op[ans[i]] = s[i];
      }
    }
  }
  for (int i = 1; i <= n; i++)
    printf("%d %c\n", a[ans[i]], (op[ans[i]] ? 'R' : 'L'));
  return 0;
}
