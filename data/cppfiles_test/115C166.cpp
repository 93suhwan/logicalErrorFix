#include <bits/stdc++.h>
using namespace std;
long long min(long long int a, long long int b) { return a < b ? a : b; }
int main() {
  int t, n;
  long long int h;
  int a[105] = {0};
  scanf("%d", &t);
  while (t--) {
    scanf("%d %lld", &n, &h);
    int len = 0;
    for (len = 1; len <= n; ++len) {
      scanf("%d", &a[len]);
    }
    long long int high = 1e18, low = 1, mid = 0;
    while (low <= high) {
      mid = (low + high) / 2;
      long long int sum = mid;
      for (int i = 1; i < n; ++i) {
        sum += min(mid, a[i + 1] - a[i]);
      }
      if (sum < h)
        low = mid + 1;
      else
        high = mid - 1;
    }
    cout << high + 1 << endl;
  }
  return 0;
}
