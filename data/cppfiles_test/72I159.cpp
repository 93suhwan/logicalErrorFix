#include <bits/stdc++.h>
using namespace std;
int n, k;
int pos;
vector<int> num;
void init() {
  while (n > 0) {
    num.push_back(n % 10);
    n /= 10;
  }
  reverse(num.begin(), num.end());
}
long long ans;
int main() {
  int t;
  cin >> t;
  while (t--) {
    num.clear();
    cin >> n >> k;
    n--;
    init();
    ans = 1e10;
    n = (int)num.size();
    for (int i = 0; i < n; i++) {
      bool flag = 0;
      int now = 0;
      for (int j = 0; j < i; j++) now |= (1 << num[j]);
      if (__builtin_popcount(now) > k) break;
      int lft = k - __builtin_popcount(now);
      long long nans = 0;
      for (int j = 0; j < i; j++) nans = nans * 10 + num[j];
      for (int j = num[i] + 1; j <= 9; j++)
        if (now & (1 << j) || lft) {
          nans = nans * 10 + j;
          if ((now & (1 << j)) == 0) lft--;
          flag = 1;
          break;
        }
      if (!flag) continue;
      if (!lft && (now & 1) == 0) {
        for (int j = 1; j <= 9; j++)
          if (now & (1 << j)) {
            for (int l = i + 1; l < n; l++) nans = nans * 10 + j;
            break;
          }
      } else {
        for (int l = i + 1; l < n; l++) nans = nans * 10;
      }
      ans = min(ans, nans);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
