#include <bits/stdc++.h>
using namespace std;
int amount;
int numbers[300005];
void solve() {
  scanf("%d", &amount);
  for (int i = 1; i <= amount; i++) scanf("%d", &numbers[i]);
  long long res = 0;
  for (int i = 2; i <= amount; i++)
    res = max(res, (long long)numbers[i] * numbers[i - 1]);
  printf("%lld\n", res);
}
int main() {
  int tester;
  scanf("%d", &tester);
  while (tester--) solve();
}
