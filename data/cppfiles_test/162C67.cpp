#include <bits/stdc++.h>
using namespace std;
int num[200005];
int num1[200005];
int n;
bool check(int x) {
  for (int i = 1; i <= n; i++) num1[i] = num[i];
  for (int i = n; i >= 1; i--) {
    if (num1[i] - 3 >= x && i >= 3) {
      int tmp = min(num1[i] - x, num[i]);
      num1[i - 1] += tmp / 3;
      num1[i - 2] += tmp / 3 * 2;
      num1[i] -= tmp;
    }
    if (num1[i] < x) return 0;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    int minn = 1145141919;
    int maxx = -1;
    for (int i = 1; i <= n; i++) {
      cin >> num[i];
      minn = min(num[i], minn);
      maxx = max(maxx, num[i]);
    }
    int l = minn, r = maxx;
    int mid, ans = 1;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (check(mid)) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
