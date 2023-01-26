#include <bits/stdc++.h>
using namespace std;
auto power = [](long long int n, long long int k, long long int mod) {
  long long int ans = 1;
  while (k) {
    if (k & 1) ans = (ans * n) % mod, k--;
    n = (n * n) % mod, k >>= 2;
  }
  return ans;
};
auto mod = [](long long int n, long long int k) {
  long long int ans = n % k;
  if (n < 0) ans += k;
  return ans;
};
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt;
  cin >> tt;
  for (int T = 1; T < tt + 1; T++) solve();
  return 0;
}
void solve() {
  long long int n;
  cin >> n;
  cout << -n + 1 << " " << n << endl;
}
