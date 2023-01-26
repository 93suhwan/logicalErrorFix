#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  long long int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] != i + 1) {
      if (pow(i + 1, 2) == arr[i] || pow(i + 1, 3) == arr[i]) {
        cout << "-1" << endl;
        return;
      }
      cnt++;
    }
  }
  cout << cnt << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
