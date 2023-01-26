#include <bits/stdc++.h>
using namespace std;
int arr[100];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  for (; t--;) {
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 0; i != n; ++i) cin >> arr[i];
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i != k; ++i) ans += arr[i + k] / arr[i];
    for (int i = k << 1; i != n; ++i) ans += arr[i];
    cout << ans << '\n';
  }
}
