#include <bits/stdc++.h>
using namespace std;
int check(int a[], int len, int mid) {
  int ans = 0;
  for (int i = 0; i < len - 1; i++) {
    if (a[i + 1] - a[i] > mid) {
      ans = ans + mid;
    } else {
      ans = ans + (a[i + 1] - a[i]);
    }
  }
  ans = ans + mid;
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, h;
    cin >> n >> h;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    int start = 1, end = h, mid, sol;
    while (start <= end) {
      mid = start + (end - start) / 2;
      int ans = check(a, n, mid);
      if (ans < h) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    cout << start << endl;
  }
}
