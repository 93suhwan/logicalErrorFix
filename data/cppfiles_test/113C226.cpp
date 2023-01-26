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
  vector<long long> arr(n);
  for (long long& x : arr) cin >> x;
  sort(arr.begin(), arr.end());
  long long sum = accumulate(arr.begin(), arr.end(), 0LL);
  int m;
  cin >> m;
  while (m--) {
    long long a, b;
    cin >> a >> b;
    long long attack1 = lower_bound(arr.begin(), arr.end(), a) - arr.begin();
    long long coins = 2e18;
    if (attack1 > 0)
      coins = minl(coins, a - arr[attack1 - 1] +
                              maxl(0LL, b - (sum - arr[attack1 - 1])));
    if (attack1 < n) coins = minl(coins, maxl(0LL, b - (sum - arr[attack1])));
    cout << coins << '\n';
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
