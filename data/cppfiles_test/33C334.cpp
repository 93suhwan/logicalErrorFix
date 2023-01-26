#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int arr[n];
    long long int ans = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (int i = 1; i < n; i++) {
      ans = max(ans, arr[i] * arr[i - 1]);
    }
    cout << ans << endl;
  }
}
