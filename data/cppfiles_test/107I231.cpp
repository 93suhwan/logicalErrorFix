#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int cnt, n, q, pos;
char s[N], ch;
int main() {
  scanf("%d %d %s", &n, &q, s + 1);
  for (int i = 1; i + 2 <= n; i++)
    if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') cnt++;
  while (q--) {
    int sum = 0;
    scanf("%d %c", &pos, &ch);
    if (s[pos] == 'a' && s[pos + 1] == 'b' && s[pos + 2] == 'c' && pos + 2 <= n)
      sum++;
    if (s[pos] == 'b' && s[pos - 1] == 'a' && s[pos + 1] == 'c' &&
        pos + 1 <= n && pos - 1 <= 1)
      sum++;
    if (s[pos] == 'c' && s[pos - 1] == 'b' && s[pos - 2] == 'a' && pos + 2 <= 2)
      sum++;
    if (ch == 'a' && s[pos + 1] == 'b' && s[pos + 2] == 'c' && pos + 2 <= n)
      sum--;
    if (ch == 'b' && s[pos - 1] == 'a' && s[pos + 1] == 'c' && pos + 1 <= n &&
        pos - 1 <= 1)
      sum--;
    if (ch == 'c' && s[pos - 1] == 'b' && s[pos - 2] == 'a' && pos + 2 <= 2)
      sum--;
    printf("%d\n", cnt - sum);
  }
  return 0;
}
