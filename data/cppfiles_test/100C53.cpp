#include <bits/stdc++.h>
using namespace std;
long long extr(long long arr[], int n) {
  if (n == 1) return arr[0];
  long long ans = arr[0];
  for (int i = 1; i < n; i++) {
    ans = max(ans, arr[i] - arr[i - 1]);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    cout << extr(arr, n) << '\n';
  }
  return 0;
}
