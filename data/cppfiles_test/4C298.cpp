#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, i, j, k = 0, f, x, y, z, ans;
  long long t;
  cin >> t;
  while (t--) {
    m = 0, i = 0, j = 0, f = 0, x = 0, y = 0, z = 0, ans = 0;
    cin >> n;
    if (n == 5)
      cout << "2 4\n";
    else
      cout << 2 << " " << (n - 1) / 2 << "\n";
  }
  return 0;
}
