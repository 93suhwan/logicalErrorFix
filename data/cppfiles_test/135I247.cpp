#include <bits/stdc++.h>
using namespace std;
int arr[100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, k, i, j, sum;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    sum = 0;
    for (i = n - k * 2; i < n - k; i++) {
      if (arr[i] == arr[i + k]) {
        sum++;
      } else {
        break;
      }
    }
    for (i = 0; i < n - k * 2; i++) {
      sum = sum + arr[i];
    }
    cout << sum << endl;
  }
  return 0;
}
