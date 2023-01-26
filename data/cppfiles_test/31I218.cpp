#include <bits/stdc++.h>
using namespace std;
struct bs {
  int x;
  int index;
} a[100010];
bool cmp(bs A, bs B) { return A.x < B.x; }
int n;
void solve() {
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x;
    a[i].index = i;
    sum += a[i].x;
  }
  sort(a + 1, a + 1 + n, cmp);
  int l = -1;
  int ans = -1;
  if (sum > 0) {
    for (int i = n; i >= 1; i--) {
      int x = abs(a[i].x);
      if (sum % x == 0) {
        l = a[i].index;
        ans = sum / x - 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i == l)
        cout << ans << " ";
      else
        cout << 1 << " ";
    }
    cout << endl;
  } else {
    for (int i = n; i >= 1; i--) {
      sum = -1 * sum;
      int x = abs(a[i].x);
      if (sum % x == 0) {
        l = a[i].index;
        ans = sum / x - 1;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i == l)
        cout << ans << " ";
      else
        cout << 1 << " ";
    }
    cout << endl;
  }
  return;
}
int main() {
  int T = 1;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
