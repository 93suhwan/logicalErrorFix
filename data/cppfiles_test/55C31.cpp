#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int k;
long long a[70];
int main(void) {
  a[0] = 4;
  for (int i = 1; i <= 60; i++) {
    a[i] = (a[i - 1] * a[i - 1]) % mod;
  }
  cin >> k;
  long long ans = 6;
  for (int i = 1; i < k; i++) {
    ans = (ans * a[i]) % mod;
  }
  cout << ans << endl;
  return 0;
}
