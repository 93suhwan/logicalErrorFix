#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] -= i;
  }
  sort(arr + 1, arr + n + 1);
  if (arr[n] <= 0)
    cout << 0 << endl;
  else
    cout << arr[n] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
