#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  for (int i = 0; i < n / 2; i++) {
    cout << arr[i + 1] << " " << arr[0] << endl;
  }
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
