#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  ;
  long long int h;
  cin >> h;
  ;
  vector<long long int> a(0 + n);
  for (int i = 0; i < 0 + n; i++) {
    cin >> a[i];
  };
  if (n == 1) {
    cout << h << "\n";
  }
  int l = 1, r = h;
  while (l < r) {
    long long int mid = (l + r) / 2;
    long long int m = 0;
    for (int i = 0; i < n - 1; i++) {
      m += min(mid, a[i + 1] - a[i]);
    }
    m += mid;
    if (m > h) {
      r = mid;
    } else if (m < h) {
      l = mid + 1;
    } else {
      cout << mid << "\n";
      return;
    }
  }
  cout << l << "\n";
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
