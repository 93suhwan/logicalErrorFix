#include <bits/stdc++.h>
using namespace std;
const long long mod1 = 998244353;
const long long mod2 = 1000000007;
int res, t, n;
int r[50005][5];
bool first_greater_than_second(int i, int j) {
  int cnt = 0;
  for (int a = 0; a < (5); ++a) {
    if (r[i][a] < r[j][a]) ++cnt;
  }
  return (cnt >= 3);
}
void Q() {
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i) {
    scanf("%d%d%d%d%d", &r[i][0], &r[i][1], &r[i][2], &r[i][3], &r[i][4]);
  }
  res = 0;
  for (int i = 1; i < n; ++i) {
    if (first_greater_than_second(i, res)) {
      res = i;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (first_greater_than_second(i, res)) {
      printf("-1\n");
      return;
    }
  }
  printf("%d\n", ++res);
}
int main() {
  cin >> t;
  while (t--) Q();
  return 0;
}
