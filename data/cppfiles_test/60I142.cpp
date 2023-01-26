#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int arr[n];
  int sub[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int sum = arr[0];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sum = min(arr[j] & arr[i], sum);
    }
  }
  cout << sum;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
}
