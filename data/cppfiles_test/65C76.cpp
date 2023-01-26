#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, a[N], ans[N];
char s[N];
signed main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%s", s + 1);
  sort(a + 1, a + n + 1);
  for (int l = 1, r = n, i = n; i; i--)
    if (s[i] == s[i - 1])
      ans[i] = l++;
    else
      ans[i] = r--;
  for (int i = 1; i <= n; i++)
    printf("%d %c\n", a[ans[i]],
           (ans[i] & 1) ^ (n & 1) ^ (s[n] == 'R') ? 'R' : 'L');
  return 0;
}
