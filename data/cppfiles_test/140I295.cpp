#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    int l = -1, r = x + 1;
    while (l + 1 != r) {
      long long mid = l + r >> 1;
      if (long long(mid * mid) <= x) {
        l = mid;
      } else {
        r = mid;
      }
    }
    int sq = l;
    l = -1, r = x + 1;
    while (l + 1 != r) {
      long long mid = l + r >> 1;
      if (long long(mid * mid * mid) <= x) {
        l = mid;
      } else {
        r = mid;
      }
    }
    int cu = l;
    printf("%d\n", sq + cu - 1);
  }
  return 0;
}
