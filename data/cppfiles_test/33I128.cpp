#include <bits/stdc++.h>
using namespace std;
void seive(long long);
bool cmp(long long, long long);
vector<bool> prime(200002, true);
void solve() {
  long long n, i, j, k;
  cin >> n;
  long long arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (n == 2) {
    cout << arr[0] * arr[1] << endl;
    return;
  }
  long long maximum = INT_MIN, prod = 1, second = 0;
  for (i = 0; i < n; i++) {
    if (arr[i] > maximum) {
      maximum = arr[i];
    }
  }
  prod = prod * maximum;
  for (i = 0; i < n; i++) {
    if (arr[i] == maximum) {
      if (i == 0) {
        prod = max(prod, maximum * arr[i + 1]);
      } else if (i == n - 1) {
        prod = max(prod, maximum * arr[i - 1]);
      } else {
        prod = max(prod, max(arr[i - 1] * arr[i], arr[i + 1] * arr[i]));
      }
    }
  }
  cout << prod << endl;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
void seive(long long mx) {
  prime[0] = prime[1] = false;
  for (long long i = 2; i * i <= mx; i++) {
    if (prime[i]) {
      for (long long j = i * i; j <= mx; j += i) {
        prime[j] = false;
      }
    }
  }
}
bool cmp(long long x, long long y) {
  if (x > y)
    return true;
  else
    return false;
}
