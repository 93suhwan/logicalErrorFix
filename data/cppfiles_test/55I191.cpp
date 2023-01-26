#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long m) {
  long long ans = 1;
  a = a % m;
  while (b) {
    if (b & 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans;
}
long long mod_Inverse(long long a, long long m) { return power(a, m - 2, m); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int k;
  cin >> k;
  long long ans = 6;
  ans = (ans * power(4, power(2, k, 1000000007), 1000000007) - 2) % 1000000007;
  cout << ans << '\n';
}
