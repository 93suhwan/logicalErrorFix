#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int arr[n];
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long int count = 0;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = i + 1; j < n; j++) {
      long long int mod1 = arr[j] % arr[i];
      long long int mod2 = arr[i] % arr[j];
      if (!binary_search(arr, arr + n, mod1)) {
        cout << arr[j] << " " << arr[i] << "\n";
        count++;
      } else if (!binary_search(arr, arr + n, mod2)) {
        cout << arr[i] << " " << arr[j] << "\n";
        count++;
      }
      if (count == n / 2) {
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
