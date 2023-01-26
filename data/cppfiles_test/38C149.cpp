#include <bits/stdc++.h>
int maz[1000010], fal[1000010];
int main() {
  int n, m, q, a, b;
  char c;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n * m; ++i) {
    do scanf("%c", &c);
    while (c == '\n');
    if (c == '.')
      maz[i] = 1;
    else
      maz[i] = 0;
  }
  for (int i = 1; i < m; ++i)
    for (int j = i + m; j < n * m; j += m) {
      if (!maz[j - 1] && !maz[j - m]) fal[i] = 1;
    }
  for (int i = 2; i < m; ++i) fal[i] += fal[i - 1];
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &a, &b);
    if (fal[a - 1] == fal[b - 1])
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
