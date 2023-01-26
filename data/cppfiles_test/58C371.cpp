#include <bits/stdc++.h>
char arr[5][210];
void testc() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= 2; i++) scanf("%s", &arr[i][1]);
  if (arr[1][1] == '1' || arr[2][n] == '1') return void(printf("NO"));
  for (int i = 1; i <= n; i++)
    if (arr[1][i] == '1' && arr[2][i] == '1') return void(printf("NO"));
  printf("YES");
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    testc();
    if (t) putchar('\n');
  }
  return 0;
}
