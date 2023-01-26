#include <bits/stdc++.h>
using namespace std;
int T;
long long n, k, p, ans, sum, bit[10];
bool sol, over;
void dfs(int now, int Pow) {
  if (!Pow) {
    sol = true;
    return;
  }
  long long num = now / Pow, add = 0;
  if (over) {
    if (bit[0]) {
      bit[0]++;
      dfs(now % Pow, Pow / 10);
    } else {
      if (sum < k) {
        sum++;
        bit[0]++;
        dfs(now % Pow, Pow / 10);
      } else {
        int low = -1;
        for (int i = 1; i < 10; i++)
          if (bit[i]) {
            low = i;
            break;
          }
        bit[low]++;
        dfs(now % Pow, Pow / 10);
        ans += low * Pow;
      }
    }
    return;
  }
  if (sum < k) {
    add = num * Pow;
    if (!bit[num]) sum++;
    bit[num]++;
    dfs(now % Pow, Pow / 10);
    if (sol) {
      ans += add;
      return;
    }
    bit[num]--;
    ans %= Pow;
    if (!bit[num]) sum--;
    if (num == 9) return;
    add += Pow;
    if (!bit[num + 1]) sum++;
    bit[num + 1]++;
    over = true;
    dfs(now % Pow, Pow / 10);
    ans += add;
  } else {
    if (bit[num]) {
      add = num * Pow;
      bit[num]++;
      dfs(now % Pow, Pow / 10);
      if (sol) {
        ans += add;
        return;
      }
      ans %= Pow;
      bit[num]--;
    }
    int low = -1;
    for (int i = num + 1; i < 10; i++)
      if (bit[i]) {
        low = i;
        break;
      }
    if (low == -1) return;
    bit[low]++;
    add = low * Pow;
    over = true;
    dfs(now % Pow, Pow / 10);
    ans += add;
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    p = 1;
    ans = sum = 0;
    memset(bit, 0, sizeof(bit));
    over = sol = false;
    scanf("%lld%lld", &n, &k);
    while (n / p) p *= 10;
    dfs(n, p / 10);
    printf("%d\n", ans);
  }
  return 0;
}
