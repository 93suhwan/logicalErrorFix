#include <bits/stdc++.h>
using namespace std;
long long int pwr(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 1000000007;
    }
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res;
}
int main() {
  long long int k, ans = 1, nodes = 0;
  cin >> k;
  nodes = (pwr(2, k) % 1000000007);
  nodes -= 2;
  ans = pwr(4, nodes) % 1000000007;
  ans = (ans * 6) % 1000000007;
  cout << ans << "\n";
  return 0;
}
