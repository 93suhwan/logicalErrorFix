#include <bits/stdc++.h>
using namespace std;
long long arr[100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, n, k, i, sum;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    sum = 0;
    for (i = n - 1; i >= 0; i--) {
      if (k == 0) {
        sum = sum + arr[i];
      } else {
        sum = sum + (arr[i - 1] / arr[i]);
        k--;
        i--;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
