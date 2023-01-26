#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
long long int maxl(long long int a, long long int b) {
  if (a > b) return a;
  return b;
}
long long int minl(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
long long int absl(long long int a) {
  if (a < 0) return -a;
  return a;
}
void testCase() {
  int n;
  cin >> n;
  long long arr[n];
  for (long long& x : arr) cin >> x;
  sort(arr, arr + n);
  long long sum = 0;
  for (int x : arr) sum += x;
  int m;
  cin >> m;
  while (m--) {
    long long a, b;
    cin >> a >> b;
    long long attack1 = lower_bound(arr, arr + n, a) - arr;
    if (attack1 >= n) attack1 = n - 1;
    long long ans;
    ans = maxl(0, a - arr[attack1]) + maxl(0, b - (sum - arr[attack1]));
    if (attack1 > 0)
      ans = minl(ans, maxl(0, a - arr[attack1 - 1]) +
                          maxl(0, b - (sum - arr[attack1 - 1])));
    cout << ans << '\n';
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    testCase();
  }
  return 0;
}
