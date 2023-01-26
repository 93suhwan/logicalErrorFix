#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
void testCase() {
  int n;
  cin >> n;
  long long arr[n];
  for (long long& x : arr) cin >> x;
  sort(arr, arr + n);
  int sum = 0;
  for (int x : arr) sum += x;
  int m;
  cin >> m;
  while (m--) {
    long long a, b;
    cin >> a >> b;
    long long attack = *(lower_bound(arr, arr + n, a) - 1);
    long long coins = a - attack;
    if (sum - attack < b) coins += b - (sum - attack);
    if (coins < 0) coins = 0;
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
