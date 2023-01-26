#include <bits/stdc++.h>
using namespace std;
int GCD(int A, int B) { return (B == 0) ? A : GCD(B, A % B); }
int LCM(int A, int B) { return A * B / GCD(A, B); }
const int mod = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int power(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = (res * 1ll * a) % mod;
    n = n >> 1;
    a = (a * 1ll * a) % mod;
  }
  return res;
}
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char dir[4] = {'R', 'L', 'D', 'U'};
const int maxN = 200005;
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  int ans = arr[0];
  for (int i = 1; i < n; i++) ans &= arr[i];
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
