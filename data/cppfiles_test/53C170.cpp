#include <bits/stdc++.h>
using namespace std;
int bsg(int arr[], int n, int v) {
  int l = 0, r = n - 1, m;
  while (l <= r) {
    m = (l + r) / 2;
    if (arr[m] == v) return m;
    if (arr[m] > v) {
      if (m == l || arr[m - 1] < v) return m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return n;
}
int bsl(int arr[], int n, int v) {
  int l = 0, r = n - 1, m;
  while (l <= r) {
    m = (l + r) / 2;
    if (arr[m] == v) return m;
    if (arr[m] < v) {
      if (m == r || arr[m + 1] > v) return m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  return -1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, j, k, p, q;
    cin >> n >> k;
    int arr[n], brr[n];
    for (i = 0; i < n; i++) {
      cin >> arr[i];
      brr[i] = arr[i];
    }
    sort(brr, brr + n);
    j = 1;
    for (i = 1; i < n; i++) {
      if (arr[i] < arr[i - 1])
        j++;
      else {
        p = bsg(brr, n, arr[i - 1] + 1);
        q = bsl(brr, n, arr[i] - 1);
        if (p <= q) j++;
      }
    }
    if (j <= k)
      cout << "Yes" << endl;
    else
      cout << "No\n";
  }
  return 0;
}
