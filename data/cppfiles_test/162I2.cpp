#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
long long t, n, a[N], v[N];
bool check(int mid) {
  for (int i = 0; i < n; i++) v[i] = a[i];
  for (int i = n - 1; i >= 2; i--) {
    if (v[i] < mid) {
      return false;
    }
    int d = min(a[i], v[i] - mid);
    d /= 3;
    v[i - 1] += d;
    v[i - 2] += 2 * d;
  }
  if (v[0] >= mid && v[1] >= mid)
    return true;
  else
    return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int l = 0, r = 200010;
    while (l < r) {
      int mid = l + r + 1 >> 1;
      if (check(mid)) {
        l = mid;
      } else
        r = mid - 1;
    }
    cout << r << endl;
  }
  return 0;
}
