#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int fpow(int x, long long p) {
  int ans = 1;
  long long pows = x;
  while (p) {
    if (p & 1) {
      ans = (ans * pows) % MOD;
    }
    pows = (pows * pows) % MOD;
    p >>= 1;
  }
  return ans;
}
int main() {
  int K;
  cin >> K;
  long long ans = 6;
  ans = (ans * fpow(4, (1ll << K) - 2)) % MOD;
  cout << ans << endl;
  return 0;
}
