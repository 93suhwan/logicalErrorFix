#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 55;
long long a[N], add[N];
int n;
bool check(int mid) {
  for (int i = 1; i <= n; i++) add[i] = 0;
  for (int i = n; i >= 3; i--) {
    long long val = (a[i] - mid + add[i]) / 3;
    val = min(val, a[i] / 3);
    if (a[i] - mid + add[i] < 0) return false;
    add[i - 2] += 2 * val;
    add[i - 1] += val;
  }
  if (a[1] + add[1] < mid || a[2] + add[2] < mid) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test;
  cin >> test;
  while (test--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 0, r = 1e9, mid = 0;
    while (true) {
      mid = (l + r) >> 1;
      if (mid == l || mid == r) break;
      if (check(mid) == 1)
        l = mid;
      else
        r = mid;
    }
    for (int i = r; i >= l; i--)
      if (check(i)) {
        cout << i << "\n";
        break;
      }
  }
}
