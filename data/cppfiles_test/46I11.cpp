#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long int binexp(long long int a, long long int b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int ncr(long long int n, long long int r) {
  if (r == 1) return n;
  if (r == 0) return 1;
  r = min(r, n - r);
  long long int ans = 1LL;
  for (int i = 0; i < r; i++) {
    ans = (ans * (n - i)) / (i + 1);
  }
  return ans;
}
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < arr.size(); i++) cin >> arr[i];
  long long int ans = 0;
  long long int maxima = *max_element(arr.begin(), arr.end());
  vector<int> b = arr;
  sort((b).begin(), (b).end());
  if (arr[n - 1] == maxima) {
    cout << 0 << endl;
    return;
  } else {
    for (int i = n - 1; i >= 0; i--) {
      if (arr[i] == b[n - 1]) {
        break;
      } else if (arr[i] == b[n - 2]) {
        ans++;
        break;
      }
      ans++;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
