#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, k, ans = 0;
  cin >> n >> k;
  long long arr[n], b = n - 2 * k;
  long long b1 = b, k1 = k;
  for (long long i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  for (long long i = 0; i < b; i++) ans += arr[i];
  long long brr[2 * k];
  while (k--) {
    ans += arr[b1] / arr[b1 + k1];
    b1++;
  }
  cout << ans;
  return;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
