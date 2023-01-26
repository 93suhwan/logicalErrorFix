#include <bits/stdc++.h>
using namespace std;
int cnt[200001];
void solve() {
  int mm, sum, n, num, ans;
  memset(cnt, 0, sizeof(cnt));
  sum = ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num);
    sum += num;
    cnt[num]++;
  }
  mm = sum / n;
  if (n * mm != sum) {
    printf("0\n");
    return;
  }
  for (int i = 0; i <= mm - 1; i++) {
    ans += cnt[i] * cnt[2 * mm - i];
  }
  ans += cnt[mm] * (cnt[mm] - 1) / 2;
  printf("%d\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
