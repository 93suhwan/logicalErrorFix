#include <bits/stdc++.h>
using namespace std;
const int MAX = 200007;
long long int mod = 1e9 + 7;
int power(long long int n, long long int y) {
  long long int res = 1;
  n = n % mod;
  if (n == 0) {
    return 0;
  }
  while (y > 0) {
    if (y & 1) res = (res * n) % mod;
    y = y >> 1;
    n = (n * n) % mod;
  }
  return res;
}
int Binary(int n) {
  int ans = 0;
  for (int i = 30; i >= 0; i--) {
    int temp = n >> i;
    if ((temp & 1) == 1) {
      ans++;
    }
  }
  return ans;
}
void solve() {
  int n, s;
  cin >> n >> s;
  int idx;
  if (n % 2 == 0) {
    idx = n / 2 + 1;
  } else {
    idx = n - n / 2;
  }
  cout << s / idx << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
