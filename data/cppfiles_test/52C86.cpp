#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void solve(int _t) {
  long long n, k;
  cin >> n >> k;
  long long ans = 0, x = 1, power[32];
  power[0] = 1;
  for (int i = 1; i < 32; i++) {
    power[i] = (power[i - 1] * n) % mod;
  }
  for (int i = 0; i < 32; i++) {
    ans += (power[i] * ((k & (1 << i)) != 0));
    ans %= mod;
  }
  cout << ans << '\n';
}
int main() {
  int t = 1;
  cin >> t;
  for (int i = 0; i < t; i++) solve(i + 1);
  return 0;
}
