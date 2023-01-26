#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 55;
long long a[N], b[N], add[N], n;
bool check(int mid) {
  for (int i = 1; i <= n; i++) b[i] = a[i];
  add[n] = 0;
  for (int i = n; i >= 3; i--) {
    long long val = (b[i] - mid + add[i]) / 3;
    if (b[i] - mid + add[i] < 0) return false;
    add[i - 2] += 2 * val;
    add[i - 1] += val;
  }
  if (b[1] + add[1] < mid || b[2] + add[2] < mid) return false;
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
    long long l = 0, r = 1e11;
    while (true) {
      int mid = (l + r) >> 1;
      if (mid == l || mid == r) break;
      if (check(mid))
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
