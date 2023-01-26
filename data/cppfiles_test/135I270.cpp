#include <bits/stdc++.h>
using namespace std;
long long int countDistinct(long long int arr[], long long int n,
                            long long int x) {
  long long int res = 1;
  for (long long int i = x; i < n; i++) {
    long long int j = 0;
    for (j = 0; j < i; j++)
      if (arr[i] == arr[j]) break;
    if (i == j) res++;
  }
  return res;
}
int32_t main() {
  long long int n, m, i, j, k, x, t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long int arr[n];
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    long long int sum = 0;
    x = n - 2 * k;
    for (i = 0; i < x; i++) {
      sum += arr[i];
    }
    j = 1;
    for (i = x; i < n - 1; i++) {
      if (arr[i] != arr[i + 1]) {
        j++;
      }
    }
    cout << sum + max((k + 1 - j), 0ll) << "\n";
  }
}
