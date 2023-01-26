#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9;
const int N = 31;
const int M = 1e9 + 7;
long long exp_bin(long long b, long long e) {
  long long ans = 1, val = b;
  while (e) {
    if (e & 1) ans = ans * val % M;
    val = val * val % M;
    e = e >> 1;
  }
  return ans;
}
int main() {
  int k;
  cin >> k;
  long long ans = 6 * exp_bin(4, (1LL << k) - 2) % M;
  cout << ans << endl;
  return 0;
}
