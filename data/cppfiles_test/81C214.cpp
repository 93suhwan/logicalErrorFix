#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      if (c == '+') {
        arr[i] = 1;
      } else {
        arr[i] = -1;
      }
    }
    int pre[n];
    pre[0] = arr[0];
    for (int i = 1; i < n; i++) {
      if (i % 2 == 1) {
        pre[i] = pre[i - 1] - arr[i];
      } else {
        pre[i] = pre[i - 1] + arr[i];
      }
    }
    while (q--) {
      int l, r;
      cin >> l >> r;
      int p;
      if (l > r) {
        p = 0;
      } else if (l - 2 < 0) {
        p = pre[r - 1];
      } else {
        p = pre[r - 1] - pre[l - 2];
      }
      if (p == 0) {
        cout << 0;
      } else if (p % 2 == 0) {
        cout << 2;
      } else {
        cout << 1;
      }
      cout << endl;
    }
  }
}
