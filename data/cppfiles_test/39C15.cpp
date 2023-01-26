#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long arr[n], ans[n];
  for (long long i = 0; i < n; i++) arr[i] = 1;
  ans[n - 1] = 1;
  for (long long i = 2; i <= n; i++) {
    arr[n - 1] = i;
    cout << "? ";
    for (long long i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << '\n';
    cout << flush;
    long long k;
    cin >> k;
    if (!k) {
      ans[n - 1] = n - i + 2;
      break;
    }
  }
  long long i = 1;
  for (long long i = 0; i < n; i++) arr[i] = ans[n - 1];
  while (i <= n) {
    if (i == ans[n - 1]) {
      i++;
      continue;
    }
    arr[n - 1] = i;
    cout << "? ";
    for (long long i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << '\n';
    cout << flush;
    long long k;
    cin >> k;
    ans[k - 1] = i;
    i++;
  }
  cout << "! ";
  for (long long i = 0; i < n; i++) cout << ans[i] << ' ';
  cout << '\n';
}
