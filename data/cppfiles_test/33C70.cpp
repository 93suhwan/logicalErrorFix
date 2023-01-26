#include <bits/stdc++.h>
using namespace std;
int main() {
  long int t;
  cin >> t;
  while (t--) {
    long int n;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long int res = 0;
    for (int i = 1; i < n; i++) {
      res = max(res, arr[i] * arr[i - 1]);
    }
    cout << res << endl;
  }
}
