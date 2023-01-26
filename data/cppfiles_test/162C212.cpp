#include <bits/stdc++.h>
using namespace std;
bool check(int mid, vector<int>& a) {
  vector<int> b = a;
  int len = a.size() - 1;
  for (int i = len; i >= 2; i--) {
    if (b[i] < mid) {
      return false;
    } else {
      int t = (b[i] - mid) / 3;
      int m = a[i] / 3;
      int tt = min(t, m);
      b[i - 1] += tt;
      b[i - 2] += 2 * tt;
    }
  }
  return b[0] >= mid && b[1] >= mid;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    int l = 100000000 + 5, r = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      l = min(l, a[i]);
      r = max(r, a[i]);
    }
    l -= 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (check(mid, a)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << r << "\n";
  }
  return 0;
}
