#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int calc(int a, int b) {
  int res, i = 0;
  while (a || b) {
    ++i;
    if (a % k != b % k) res = i;
    a /= k;
    b /= k;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  int i, j, cur = 1;
  cin >> n >> k;
  for (ans = 0; cur < n; ans++) cur *= k;
  cout << ans << endl;
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++) cout << calc(i, j) << ' ';
  return 0;
}
