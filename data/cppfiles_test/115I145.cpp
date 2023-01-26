#include <bits/stdc++.h>
using namespace std;
long int check(long int a[], long int len, long int mid) {
  long int ans = 0;
  for (long int i = 0; i < len - 1; i++) {
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
  long int t;
  cin >> t;
  while (t--) {
    long int n, h;
    cin >> n >> h;
    long int a[n];
    for (long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    long int start = 1, end = h, mid, sol;
    while (start <= end) {
      mid = start + (end - start) / 2;
      long int ans = check(a, n, mid);
      if (ans < h) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    cout << start << endl;
  }
}
