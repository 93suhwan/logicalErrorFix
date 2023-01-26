#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  bool doubleOnes = false, doubleZeros = false;
  long long int ans = 0;
  for (long long int i = 0; i <= n - 1; i++) {
    if (b[i] == a[i]) {
      if (a[i] == '1') {
        if (doubleZeros) {
          ans += 2;
          doubleZeros = false;
          doubleOnes = false;
        } else {
          doubleOnes = true;
        }
      } else {
        if (doubleOnes) {
          ans += 2;
          doubleZeros = false;
          doubleOnes = false;
        } else if (doubleZeros) {
          ans += 1;
        } else {
          doubleZeros = true;
        }
      }
    } else {
      if (doubleZeros) {
        ans += 1;
      }
      doubleZeros = doubleOnes = false;
      ans += 2;
    }
  }
  if (doubleZeros) {
    ans += 1;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
