#include <bits/stdc++.h>
using namespace std;
inline long long int mul(long long int a, long long int b) {
  return (long long int)((long long)a * b % 1000000007);
}
inline long long int inv(long long int a) {
  a %= 1000000007;
  if (a < 0) a += 1000000007;
  long long int b = 1000000007, u = 0, v = 1;
  while (a) {
    long long int t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += 1000000007;
  return u;
}
void solve() {
  long long int n;
  cin >> n;
  long long int arr[n];
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  long long int m = arr[0];
  for (long long int i = 1; i < n; i++) {
    m = max(arr[i] - arr[i - 1], m);
  }
  if (n == 1) {
    cout << arr[0] << endl;
  } else {
    cout << m << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
