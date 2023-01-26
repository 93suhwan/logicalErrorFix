#include <bits/stdc++.h>
using namespace std;
void partition(long long int arr[], long long int n) {
  long long int l = 0, r = n - 1;
  long long int x = arr[r], i = l;
  for (long long int j = l; j <= r - 1; j++) {
    if (arr[j] <= x) {
      swap(arr[i], arr[j]);
      i++;
    }
  }
  for (long long int k = n - 2; k >= i; k--) {
    swap(arr[k], arr[k + 1]);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    long long int mx = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
    }
    long long int res = 0;
    while (a[n - 1] != mx) {
      partition(a, n);
      res++;
    }
    cout << res << "\n";
    ;
  }
  return 0;
}
