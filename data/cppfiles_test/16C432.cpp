#include <bits/stdc++.h>
int T, n;
int pos[50], sum[30];
char str[50];
struct node {
  int id, d;
} a[50];
bool cmp(node a, node b) { return a.id < b.id; }
void sol() {
  scanf("%d", &n);
  scanf("%s", str + 1);
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i <= n; i++) sum[str[i] - 'a' + 1]++;
  for (int i = 1; i <= 26; i++) sum[i] += sum[i - 1];
  int ans = n;
  for (int i = 1; i <= n; i++) {
    int c = str[i] - 'a' + 1;
    if (sum[c - 1] < i && sum[c] >= i) ans--;
  }
  printf("%d\n", ans);
}
int main() {
  scanf("%d", &T);
  while (T--) sol();
  return 0;
}
