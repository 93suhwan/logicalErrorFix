#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
void solve() {
  int k;
  cin >> k;
  if (k == 1) {
    cout << 6 << endl;
    return;
  }
  int need = 0;
  int temp = 2;
  for (int i = 2; i <= k; i++) {
    need += temp;
    temp *= 2;
    temp %= 1000000007;
    need %= 1000000007;
  }
  long long ans = binpow(4, need, 1000000007) % 1000000007;
  ans *= 6;
  ans %= 1000000007;
  cout << (ans % 1000000007) << endl;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
