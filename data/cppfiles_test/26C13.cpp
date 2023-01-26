#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int t, n;
long long solve(long long n) {
  if (n == 1) return 1;
  long long ans = 1;
  n *= 2;
  for (int i = n; i > 2; i--) ans = (ans % mod) * (i % mod) % mod;
  return ans;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    long long ans = solve(n);
    cout << ans << endl;
  }
  return 0;
}
