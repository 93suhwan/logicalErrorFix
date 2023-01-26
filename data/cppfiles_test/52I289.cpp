#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    double ans = 0.0;
    int n;
    cin >> n;
    int arr[n];
    int sumi = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      sumi += arr[i];
    }
    int maxii = *max_element(arr, arr + n);
    cout << fixed << setprecision(9) << maxii + (sumi - maxii) * (1.0) / (n - 1)
         << endl;
  }
  return 0;
}
