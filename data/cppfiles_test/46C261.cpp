#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  long long maxi = INT_MIN;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    maxi = max(maxi, arr[i]);
  }
  long long current = n - 1;
  long long result = 0;
  while (arr[current] != maxi) {
    long long f = current - 1;
    while (arr[f] <= arr[current]) {
      f--;
    }
    current = f;
    result++;
  }
  cout << result << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
