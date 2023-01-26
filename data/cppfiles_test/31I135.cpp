#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0LL ? a : gcd(b, a % b); }
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans[n];
  int ind = 0;
  for (int i = 1; i < n; i++) {
    if (abs(a[i]) < abs(a[ind])) {
      ind = i;
    }
  }
  int sum = 0, x;
  for (int i = 0; i < n; i++) {
    if (ind == i) {
      continue;
    }
    if (sum > 0) {
      if (a[i] >= 0) {
        x = sum / a[i];
        if (x != 0) {
          sum = sum - x * a[i];
          ans[i] = -x;
        } else {
          sum = sum - a[i];
          ans[i] = -1;
        }
      } else {
        x = sum / (-a[i]);
        if (x != 0) {
          sum = sum + x * a[i];
          ans[i] = x;
        } else {
          sum = sum + a[i];
          ans[i] = 1;
        }
      }
    } else if (sum < 0) {
      if (a[i] >= 0) {
        x = sum / a[i];
        if (x != 0) {
          sum = sum + x * a[i];
          ans[i] = x;
        } else {
          sum = sum + a[i];
          ans[i] = 1;
        }
      } else {
        x = sum / (-a[i]);
        if (x != 0) {
          sum = sum - x * a[i];
          ans[i] = -x;
        } else {
          sum = sum - a[i];
          ans[i] = -1;
        }
      }
    } else {
      sum = sum + a[i];
      ans[i] = 1;
    }
  }
  if (sum == 0) {
    if (ans[0] < 0) {
      ans[0]--;
      sum = sum + a[0];
    } else {
      ans[0]++;
      sum = sum + a[0];
    }
  }
  ans[ind] = abs(sum);
  if (a[ind] > 0) ans[ind] = -ans[ind];
  int tt = abs(a[ind]);
  if (sum < 0) tt = -tt;
  for (int i = 0; i < n; i++) {
    if (i == ind) continue;
    ans[i] = ans[i] * tt;
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
