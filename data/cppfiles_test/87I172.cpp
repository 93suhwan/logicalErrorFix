#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int arr[n];
    int i;
    for (i = 0; i < n; i++) cin >> arr[i];
    long long int m = arr[0];
    int ind = 0;
    for (i = 0; i < n; i++) {
      if (m < arr[i]) {
        m = arr[i];
        ind = i;
      }
    }
    cout << max(m - ind - 1, (long long int)0) << '\n';
  }
}
