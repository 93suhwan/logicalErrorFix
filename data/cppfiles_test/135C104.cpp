#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
int mx = 1e9;
const long long inf = 1e18;
int get_mod(int a, int m) { return (a % m + m) % m; }
long long int add(long long int x, long long int y) {
  long long int res = x + y;
  return (res >= mod) ? res % mod : res;
}
long long int mul(long long int x, long long int y) {
  long long int res = x * y;
  return (res >= mod) ? res % mod : res;
}
long long int subs(long long int x, long long int y) {
  long long int res = x - y;
  return (res >= mod) ? res % mod : res;
}
long long int power(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if ((b & 1) == 0) {
      a = mul(a, a);
      b = b >> 1;
    } else {
      res = mul(res, a);
      b = b - 1;
    }
  }
  return res;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr.begin(), arr.end(), greater<int>());
  int count = 0;
  for (int i = 0; i < k; i++) {
    count += arr[k + i] / arr[i];
  }
  for (int i = 2 * k; i < n; i++) {
    count += arr[i];
  }
  cout << count << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
