#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, psa = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
      arr[i] = arr[i] - psa;
      psa = psa + arr[i];
    }
    sort(arr, arr + n);
    cout << arr[n - 1] << endl;
  }
}
