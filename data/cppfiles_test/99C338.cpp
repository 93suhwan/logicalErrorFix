#include <bits/stdc++.h>
using namespace std;
const long long N_max = 0;
void run_case() {
  long long n, x, ans, k1, k2, k3, k4;
  cin >> x >> n;
  ans = x;
  k1 = n / 4, k2 = n / 4, k3 = n / 4, k4 = n / 4;
  if (n % 4 == 1)
    k1 += 1;
  else if (n % 4 == 2)
    k1 += 1, k2 += 1;
  else if (n % 4 == 3)
    k1 += 1, k2 += 1, k3 += 1;
  if (x % 2 == 0) {
    ans -= (k1 * (2 + (k1 - 1) * 4)) / 2;
    ans += (k2 * (4 + (k2 - 1) * 4)) / 2;
    ans += (k3 * (6 + (k3 - 1) * 4)) / 2;
    ans -= (k4 * (8 + (k4 - 1) * 4)) / 2;
  } else {
    ans += (k1 * (2 + (k1 - 1) * 4)) / 2;
    ans -= (k2 * (4 + (k2 - 1) * 4)) / 2;
    ans -= (k3 * (6 + (k3 - 1) * 4)) / 2;
    ans += (k4 * (8 + (k4 - 1) * 4)) / 2;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1;
  cin >> T;
  while (T--) run_case();
  return 0;
}
