#include <bits/stdc++.h>
using namespace std;
long long int binpow(long long int a, long long int b) {
  if (a == 0) return 0;
  if (b == 0) return 1;
  long long int ans = 1;
  while (b > 0) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b = b >> 1;
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q1;
  cin >> q1;
  while (q1--) {
    int n;
    cin >> n;
    cout << n - 1 << " " << (n - 1) / 2 << '\n';
  }
  return 0;
}
