#include <bits/stdc++.h>
using namespace std;
long long const MOD = 1e9 + 7;
int main() {
  int k;
  cin >> k;
  int i;
  long long ans = 6;
  long long tek = 4;
  for (i = 1; i < k; i++) {
    tek *= tek;
    tek %= MOD;
    ans *= tek;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
