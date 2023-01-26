#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int l = 0, r = 2000;
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      bitset<2001> bs, bt;
      for (int i = 0; i <= mid; i++) {
        bs[i] = bt[i] = 1;
      }
      for (int i = 0; i < n; i++) {
        bt = (bt << a[i]) | (bt >> a[i]);
        bt &= bs;
      }
      if (bt.any()) {
        r = mid;
      } else {
        l = mid;
      }
    }
    cout << r << endl;
  }
}
