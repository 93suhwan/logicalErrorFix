#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
pair<int, int> caves[N];
int t, n, k;
bool check(int mid) {
  for (int i = 1; i <= n; ++i)
    if (mid >= caves[i].first)
      mid += caves[i].second;
    else
      return false;
  return true;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      int k, gmin = -1;
      scanf("%d", &k);
      for (int j = 1; j <= k; ++j) {
        int power;
        scanf("%d", &power);
        gmin = max(gmin, power + 2 - j);
      }
      caves[i] = {gmin, k};
    }
    sort(caves + 1, caves + n + 1);
    int left = -1, right = 1e9 + 10;
    while (left + 1 < right) {
      int mid = left + right >> 1;
      if (check(mid))
        right = mid;
      else
        left = mid;
    }
    cout << right << endl;
  }
  return 0;
}
