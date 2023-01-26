#include <bits/stdc++.h>
using namespace std;
long long powers[1000001] = {0};
void solve() {
  long long a, sum = 0, n;
  cin >> a;
  n = a;
  long long arr[a];
  long long ans[a];
  for (long long i = 0; i < a; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  if (sum % ((n * (n + 1)) / 2) != 0) {
    cout << "NO"
         << "\n";
    return;
  }
  sum = sum / ((n * (n + 1)) / 2);
  for (long long i = 0; i < a - 1; i++) {
    if ((arr[i + 1] - arr[i] - sum) % n != 0 ||
        (arr[i + 1] - arr[i] - sum) >= 0) {
      cout << "NO"
           << "\n";
      return;
    }
    ans[i + 1] = -(arr[i + 1] - arr[i] - sum) / n;
  }
  if ((arr[0] - arr[a - 1] - sum) % n != 0 ||
      (arr[0] - arr[a - 1] - sum) >= 0) {
    cout << "NO"
         << "\n";
    return;
  }
  cout << "YES"
       << "\n";
  ans[0] = -(arr[0] - arr[a - 1] - sum) / n;
  for (long long i = 0; i < a; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long a;
  cin >> a;
  while (a--) {
    solve();
  }
  return 0;
}
