#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int a[N];
int n;
int main() {
  int t;
  int a, b, c;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &a, &b, &c);
    int sum, d, ans, ans1;
    sum = (abs(a - b) - 1) * 2 + 2;
    ans = c + abs(a - b);
    ans1 = c - abs(a - b);
    if (ans > sum && ans1 > sum || ans1 == a || ans1 == b || ans == a ||
        ans == b || sum % 2 != 0 || sum < a || sum < b) {
      printf("-1\n");
      continue;
    }
    if (ans > sum)
      printf("%d\n", ans1);
    else
      printf("%d\n", ans);
  }
  return 0;
}
