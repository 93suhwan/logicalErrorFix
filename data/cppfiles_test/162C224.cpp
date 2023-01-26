#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const long long INF = 0x7fffffffffffffff;
using namespace std;
const int N = 2e5 + 10;
int n;
int h[N];
int h1[N];
int h2[N];
bool check(int mid) {
  for (int i = 0; i < n; i++) h1[i] = 0, h2[i] = h[i];
  bool suc = true;
  for (int i = n - 1; i >= 2; i--) {
    int sum = mid - h1[i];
    if (h2[i] < sum) {
      suc = false;
      break;
    }
    if (sum > 0) {
      int shan = h2[i] - sum;
      int dui = shan / 3;
      h2[i] -= dui * 3;
      h1[i - 1] += dui;
      h1[i - 2] += dui * 2;
    } else {
      int dui = h2[i] / 3;
      h2[i] -= dui * 3;
      h1[i - 1] += dui;
      h1[i - 2] += dui * 2;
    }
  }
  if (h2[0] + h1[0] < mid || h2[1] + h1[1] < mid) suc = false;
  if (suc)
    return true;
  else
    return false;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &h[i]);
      r = max(h[i], r);
    }
    int ans;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid)) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    cout << ans << endl;
  }
}
