#include <bits/stdc++.h>
using namespace std;
int num[200005];
int num1[200005];
int n;
bool check(int x) {
  for (int i = 1; i <= n; i++) num1[i] = num[i];
  for (int i = 1; i <= n; i++) {
    if (num1[i] < x) {
      int cha1 = 0, cha2 = 0;
      int add = 0;
      if (i + 1 > 2 && i + 1 <= n && num1[i + 1] - 3 >= x) {
        num1[i] += (num1[i + 1] - x) / 3;
        num1[i + 1] -= (num1[i + 1] - x) / 3 * 3;
      }
      if (num1[i] >= x) continue;
      int cha = x - num1[i];
      if (i + 2 <= n) {
        int de = (cha + 1) / 2 * 3;
        if (num1[i + 2] >= de) {
          num1[i + 2] -= de;
          num1[i] += cha;
          add += de / 3;
        } else {
          num1[i] += num1[i + 2] / 3 * 2;
          add += num[i + 2] / 3;
          num1[i + 2] = num1[i + 2] % 3;
        }
      }
      if (num1[i] < x && i + 1 > 2 && i + 1 <= n) {
        cha = x - num1[i];
        if (num1[i + 1] > cha * 3) {
          num1[i + 1] -= cha * 3;
          num1[i] += cha;
        } else {
          num1[i] += num1[i + 1] / 3;
          num1[i + 1] = num1[i + 1] % 3;
        }
      }
      num1[i + 1] += add;
      if (num1[i] < x) return 0;
    }
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
    int mid, ans;
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
