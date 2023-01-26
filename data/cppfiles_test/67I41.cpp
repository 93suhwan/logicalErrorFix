#include <bits/stdc++.h>
using namespace std;
long double eps = 1e-8;
void solve() {
  int64_t n;
  long double p;
  cin >> n >> p;
  for (int i = 0; i < n; ++i) {
    long double res = 0;
    long double cnt = (n * (n - 1) * (n - 2)) / 3;
    long double nn = n;
    long double chance_to_0 =
        max((long double)0,
            (nn - i) * (nn - i - 1) * (nn - i - 2) / (nn * nn * nn));
    long double chance_to_1 =
        max((long double)0, i * (nn - i) * (nn - i - 1) * 3 / (nn * nn * nn));
    long double chance_to_2 =
        max((long double)0, i * (i - 1) * (nn - i) * 3 / (nn * nn * nn));
    long double chance_to_3 = 1 - chance_to_1 - chance_to_2 - chance_to_0;
    if (chance_to_3 + chance_to_2 + chance_to_1 / 3 + eps > p) {
      cout << i << endl;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t > 0) {
    t--;
    solve();
  }
}
