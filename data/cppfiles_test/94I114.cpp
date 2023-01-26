#include <bits/stdc++.h>
using namespace std;
int findXOR(int n) {
  int mod = n % 4;
  if (mod == 0)
    return n;
  else if (mod == 1)
    return 1;
  else if (mod == 2)
    return n + 1;
  else if (mod == 3)
    return 0;
}
bool ispfs(long double x) {
  if (x >= 0) {
    long long sr = sqrt(x);
    return (sr * sr == x);
  }
  return false;
}
int findXOR(int l, int r) { return (findXOR(l - 1) ^ findXOR(r)); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int ans = ceil(sqrt(n));
    if (n < 10) {
      cout << n - 1 << '\n';
    } else if (ispfs(n) == true) {
      cout << ans - 1 << '\n';
    } else if (n % 2 != 0) {
      cout << ans - 1 << '\n';
    } else if (n % 2 == 0) {
      cout << ans << '\n';
    }
  }
}
