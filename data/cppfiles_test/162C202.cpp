#include <bits/stdc++.h>
using namespace std;
void solve(int test) {
  int n;
  cin >> n;
  vector<int> v(n);
  int l = 1, h = 1;
  for (int i = 0; i < n; i++) cin >> v[i], h = max(h, v[i]);
  int ans = 1;
  while (l <= h) {
    int mid = (l + h) / 2;
    vector<int> tmp = v;
    int f = 0;
    for (int i = n - 1; i >= 2; i--) {
      if (tmp[i] < mid) {
        h = mid - 1;
        f = 1;
        break;
      }
      int a = min(tmp[i] - mid, v[i]);
      tmp[i - 1] += a / 3;
      tmp[i - 2] += 2 * (a / 3);
    }
    if (f == 1) continue;
    if (tmp[0] >= mid && tmp[1] >= mid) {
      ans = mid;
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  ;
  int t, test = 0;
  cin >> t;
  while (t--) {
    solve(++test);
  }
  return 0;
}
